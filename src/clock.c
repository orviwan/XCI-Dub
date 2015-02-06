#include "clock.h"
#include "helper.h"
#include <pebble.h>

static Window *s_window;

static TextLayer *s_hour_layer, *s_minute_layer, *s_second_layer, *s_day_layer, *s_date_layer;

static void initialise_ui(void) {
  s_window = window_create();
  window_set_background_color(s_window, GColorBlack);
  window_set_fullscreen(s_window, true);

  // s_hour_layer
  s_hour_layer = text_layer_create(GRect(0, 25, 144, 35));
  text_layer_set_background_color(s_hour_layer, GColorBlack);
  text_layer_set_text_color(s_hour_layer, GColorWhite);
  text_layer_set_font(s_hour_layer, fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_DROID_SERIF_34)));
  text_layer_set_text_alignment(s_hour_layer, GTextAlignmentCenter);
	
	layer_add_child(window_get_root_layer(s_window), (Layer *)s_hour_layer);

  // s_minute_layer
  s_minute_layer = text_layer_create(GRect(0, 60, 144, 35));
  text_layer_set_background_color(s_minute_layer, GColorBlack);
  text_layer_set_text_color(s_minute_layer, GColorWhite);
  text_layer_set_font(s_minute_layer, fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_DROID_SERIF_30)));
  text_layer_set_text_alignment(s_minute_layer, GTextAlignmentCenter);
  
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_minute_layer);

	//s_second_layer
  s_second_layer = text_layer_create(GRect(0, 94, 144, 35));
  text_layer_set_background_color(s_second_layer, GColorBlack);
  text_layer_set_text_color(s_second_layer, GColorWhite);
  text_layer_set_font(s_second_layer, fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_DROID_SERIF_20)));
  text_layer_set_text_alignment(s_second_layer, GTextAlignmentCenter);

  layer_add_child(window_get_root_layer(s_window), (Layer *)s_second_layer);
	
	//s_date_layer
  s_date_layer = text_layer_create(GRect(0, 145, 144, 15));
  text_layer_set_background_color(s_date_layer, GColorBlack);
  text_layer_set_text_color(s_date_layer, GColorWhite);
  //text_layer_set_text(s_date_layer, "Ante Diem XVIII Kalends");
  text_layer_set_font(s_date_layer, fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_DROID_SERIF_11)));
  text_layer_set_text_alignment(s_date_layer, GTextAlignmentCenter);

  layer_add_child(window_get_root_layer(s_window), (Layer *)s_date_layer);
	
	//s_day_layer
  s_day_layer = text_layer_create(GRect(0, 130, 144, 15));
  text_layer_set_background_color(s_day_layer, GColorBlack);
  text_layer_set_text_color(s_day_layer, GColorWhite);
  //text_layer_set_text(s_day_layer, "Dies Mercurii");
  text_layer_set_font(s_day_layer, fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_DROID_SERIF_11)));
  text_layer_set_text_alignment(s_day_layer, GTextAlignmentCenter);

  layer_add_child(window_get_root_layer(s_window), (Layer *)s_day_layer);
		

}

static void destroy_ui(void) {
  window_destroy(s_window);
  text_layer_destroy(s_hour_layer);
  text_layer_destroy(s_minute_layer);
  text_layer_destroy(s_second_layer);
}

unsigned short get_display_hour(unsigned short hour) {
  if (clock_is_24h_style()) {
    return hour;
  }
  unsigned short display_hour = hour % 12;
  // Converts "0" to "12"
  return display_hour ? display_hour : 12;
}

static void handle_tick(struct tm *tick_time, TimeUnits units_changed) {
	if(units_changed & DAY_UNIT) {
		text_layer_set_text(s_day_layer, roman_day_name(tick_time->tm_wday));
		text_layer_set_text(s_date_layer, julian_day_name(tick_time->tm_mon+1, tick_time->tm_mday));
	}
  if (units_changed & HOUR_UNIT) {
    text_layer_set_text(s_hour_layer, digit_to_roman_numeral(get_display_hour(tick_time->tm_hour)));
  }
  if (units_changed & MINUTE_UNIT) {
    text_layer_set_text(s_minute_layer, digit_to_roman_numeral(get_display_hour(tick_time->tm_min)));
  } 
  if (units_changed & SECOND_UNIT) {
    text_layer_set_text(s_second_layer, digit_to_roman_numeral(get_display_hour(tick_time->tm_sec)));
  }  
}

static void handle_window_unload(Window* window) {
    destroy_ui();
}

void show_clock(void) {
    initialise_ui();
    window_set_window_handlers(s_window, (WindowHandlers) {
        .unload = handle_window_unload,
    });
    window_stack_push(s_window, true);

	  //Somebody set us up the CLOCK
    time_t now = time(NULL);
    struct tm *tick_time = localtime(&now);  

    handle_tick(tick_time, DAY_UNIT + HOUR_UNIT + MINUTE_UNIT + SECOND_UNIT);
    tick_timer_service_subscribe(SECOND_UNIT, handle_tick);

}

void hide_clock(void) {
    window_stack_remove(s_window, true);
}
