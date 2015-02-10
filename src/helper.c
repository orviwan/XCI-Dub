#include <pebble.h>
	
/*
XCI Dub
 
8:38
VIII:XXXVIII

23:38
XXIII:XXXVIII

http://www.unrv.com/culture/julian-calendar-chart.php
*/

const char *roman_day_name(int day) {
	switch(day) {
		case 0: return "Dies Solis";
		case 1: return "Dies Lunae";
		case 2: return "Dies Martis";
		case 3: return "Dies Mercurii";
		case 4: return "Dies Jovis";
		case 5: return "Dies Veneris";
		case 6: return "Dies Saturni";
		default: return "";
	};
}

const char *digit_to_roman_numeral(unsigned short digit) {
    switch (digit) {
        case 0: return "";
        case 1: return "I";
        case 2: return "II";
        case 3: return "III";
        case 4: return "IV";
        case 5: return "V";
        case 6: return "VI";
        case 7: return "VII";
        case 8: return "VIII";
        case 9: return "IX";
        case 10: return "X";
        case 11: return "XI";
        case 12: return "XII";
        case 13: return "XIII";
        case 14: return "XIV";
        case 15: return "XV";
        case 16: return "XVI";
        case 17: return "XVII";
        case 18: return "XVIII";
        case 19: return "XIX";
        case 20: return "XX";
        case 21: return "XXI";
        case 22: return "XXII";
        case 23: return "XXIII";
        case 24: return "XXIV";
        case 25: return "XXV";
        case 26: return "XXVI";
        case 27: return "XXVII";
        case 28: return "XXVIII";
        case 29: return "XXIX";
        case 30: return "XXX";
        case 31: return "XXXI";
        case 32: return "XXXII";
        case 33: return "XXXIII";
        case 34: return "XXXIV";
        case 35: return "XXXV";
        case 36: return "XXXVI";
        case 37: return "XXXVII";
        case 38: return "XXXVIII";
        case 39: return "XXXIX";
        case 40: return "XL";
        case 41: return "XLI";
        case 42: return "XLII";
        case 43: return "XLIII";
        case 44: return "XLIV";
        case 45: return "XLV";
        case 46: return "XLVI";
        case 47: return "XLVII";
        case 48: return "XLVIII";
        case 49: return "XLIX";
        case 50: return "L";
        case 51: return "LI";
        case 52: return "LII";
        case 53: return "LIII";
        case 54: return "LIV";
        case 55: return "LV";
        case 56: return "LVI";
        case 57: return "LVII";
        case 58: return "LVIII";
        case 59: return "LIX";
        default: return "";      
    };
}

const char *julian_day_name(int month, int day) {
    switch(day) {
        case 1: 
    			return "Kalends";
				case 2:
					return "Ante Diem IV Nones";
				case 3:
					if(month==3 || month==5 || month==7 || month==10) {
						return "Ante Diem V Nones";
					}
					else {
						 return "Ante Diem III Nones";
					}
				case 4:
					if(month==3 || month==5 || month==7 || month==10) {
						return "Ante Diem IV Nones";
					}
					else {
						 return "Pridie Nones";
					}
				case 5:
					if(month==3 || month==5 || month==7 || month==10) {
						return "Ante Diem III Nones";
					}
					else {
						 return "Nones";
					}
				case 6:
					if(month==3 || month==5 || month==7 || month==10) {
						return "Pridie Nones";
					}
					else {
						 return "Ante Diem VIII Ides";
					}
				case 7:
					if(month==3 || month==5 || month==7 || month==10) {
						return "Nones";
					}
					else {
						 return "Ante Diem VII Ides";
					}
				case 8:
					if(month==3 || month==5 || month==7 || month==10) {
						return "Ante Diem VIII Ides";
					}
					else {
						 return "Ante Diem VI Ides";
					}
				case 9:
					if(month==3 || month==5 || month==7 || month==10) {
						return "Ante Diem VII Ides";
					}
					else {
						 return "Ante Diem V Ides";
					}
				case 10:
					if(month==3 || month==5 || month==7 || month==10) {
						return "Ante Diem VI Ides";
					}
					else {
						 return "Ante Diem IV Ides";
					}
				case 11:
					if(month==3 || month==5 || month==7 || month==10) {
						return "Ante Diem V Ides";
					}
					else {
						 return "Ante Diem III Ides";
					}
				case 12:
					if(month==3 || month==5 || month==7 || month==10) {
						return "Ante Diem IV Ides";
					}
					else {
						 return "Pridie Ides";
					}
				case 13:
					if(month==3 || month==5 || month==7 || month==10) {
						return "Ante Diem III Ides";
					}
					else {
						 return "Ides";
					}
				case 14:
					if(month==1 || month==8 || month==12) {
						return "Ante Diem XIX Kalends";
					}
					else if(month==3 || month==5 || month==7 || month==10) {
						return "Pridie Ides";
					}
					else if (month==2) {
						return "Ante Diem XVI Kalends";
					}
					else {
						 return "Ante Diem XVIII Kalends";
					}
				case 15:
					if(month==1 || month==8 || month==12) {
						return "Ante Diem XVIII Kalends";
					}
					else if(month==3 || month==5 || month==7 || month==10) {
						return "Ides";
					}
					else if (month==2) {
						return "Ante Diem XV Kalends";
					}
					else {
						 return "Ante Diem XVII Kalends";
					}
				case 16:
					if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) {
						return "Ante Diem XVII Kalends";
					}
					else if (month==2) {
						return "Ante Diem XIV Kalends";
					}
					else {
						 return "Ante Diem XVI Kalends";
					}
				case 17:
					if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) {
						return "Ante Diem XVI Kalends";
					}
					else if (month==2) {
						return "Ante Diem XIII Kalends";
					}
					else {
						 return "Ante Diem XV Kalends";
					}
				case 18:
					if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) {
						return "Ante Diem XV Kalends";
					}
					else if (month==2) {
						return "Ante Diem XII Kalends";
					}
					else {
						 return "Ante Diem XIV Kalends";
					}
				case 19:
					if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) {
						return "Ante Diem XIV Kalends";
					}
					else if (month==2) {
						return "Ante Diem XI Kalends";
					}
					else {
						 return "Ante Diem XIII Kalends";
					}
				case 20:
					if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) {
						return "Ante Diem XIII Kalends";
					}
					else if (month==2) {
						return "Ante Diem X Kalends";
					}
					else {
						 return "Ante Diem XII Kalends";
					}
				case 21:
					if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) {
						return "Ante Diem XII Kalends";
					}
					else if (month==2) {
						return "Ante Diem IX Kalends";
					}
					else {
						 return "Ante Diem XI Kalends";
					}
				case 22:
					if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) {
						return "Ante Diem XI Kalends";
					}
					else if (month==2) {
						return "Ante Diem VIII Kalends";
					}
					else {
						 return "Ante Diem X Kalends";
					}
				case 23:
					if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) {
						return "Ante Diem X Kalends";
					}
					else if (month==2) {
						return "Ante Diem VII Kalends";
					}
					else {
						 return "Ante Diem IX Kalends";
					}
				case 24:
					if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) {
						return "Ante Diem IX Kalends";
					}
					else if (month==2) {
						return "Ante Diem VI Kalends";
					}
					else {
						 return "Ante Diem VIII Kalends";
					}
				case 25:
					if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) {
						return "Ante Diem VIII Kalends";
					}
					else if (month==2) {
						return "Ante Diem V Kalends";
					}
					else {
						 return "Ante Diem VII Kalends";
					}
				case 26:
					if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) {
						return "Ante Diem VII Kalends";
					}
					else if (month==2) {
						return "Ante Diem IV Kalends";
					}
					else {
						 return "Ante Diem VI Kalends";
					}
				case 27:
					if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) {
						return "Ante Diem VI Kalends";
					}
					else if (month==2) {
						return "Ante Diem III Kalends";
					}
					else {
						 return "Ante Diem V Kalends";
					}
				case 28:
					if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) {
						return "Ante Diem V Kalends";
					}
					else if (month==2) {
						return "Pridie Kalends";
					}
					else {
						 return "Ante Diem IV Kalends";
					}
				case 29:
					if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) {
						return "Ante Diem IV Kalends";
					}
					else if (month==2) {
						return "";
					}
					else {
						 return "Ante Diem III Kalends";
					}
				case 30:
					if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) {
						return "Ante Diem III Kalends";
					}
					else if (month==2) {
						return "";
					}
					else {
						 return "Pridie Kalends";
					}
				case 31:
					if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) {
						return "Pridie Kalends";
					}
					else if (month==2) {
						return "";
					}
					else {
						 return "Pridie Kalends";
					}
			  default: return "";
    };
}
