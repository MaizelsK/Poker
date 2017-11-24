#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <time.h>
using namespace std;

#define GET_MAST(x) (int)((x)/100)
#define GET_RANG(x) (int)((x)%100)

enum Cards { // Перечисление карт
	/*ЧЕРВИ*/h_A = 101, h_2 = 102, h_3 = 103, h_4 = 104, h_5 = 105, h_6 = 106, h_7 = 107, h_8 = 108, h_9 = 109, h_10 = 110, h_J = 111, h_Q = 112, h_K = 113,
	/*БУБИ*/d_A = 201, d_2 = 202, d_3 = 203, d_4 = 204, d_5 = 205, d_6 = 206, d_7 = 207, d_8 = 208, d_9 = 209, d_10 = 210, d_J = 211, d_Q = 212, d_K = 213,
	/*КРЕСТИ*/c_A = 301, c_2 = 302, c_3 = 303, c_4 = 304, c_5 = 305, c_6 = 306, c_7 = 307, c_8 = 308, c_9 = 309, c_10 = 310, c_J = 311, c_Q = 312, c_K = 313,
	/*ПИКИ*/p_A = 401, p_2 = 402, p_3 = 403, p_4 = 404, p_5 = 405, p_6 = 406, p_7 = 407, p_8 = 408, p_9 = 409, p_10 = 410, p_J = 411, p_Q = 412, p_K = 413
};

static Cards s[52] = { // Готовый массив со всеми картами
	h_A, h_2, h_3, h_4, h_5, h_6, h_7, h_8, h_9, h_10, h_J, h_Q, h_K,
	d_A, d_2, d_3, d_4, d_5, d_6, d_7, d_8, d_9, d_10, d_J, d_Q, d_K,
	c_A, c_2, c_3, c_4, c_5, c_6, c_7, c_8, c_9, c_10, c_J, c_Q, c_K,
	p_A, p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9, p_10, p_J, p_Q, p_K
};

inline const char* ToString(Cards v)
{
	switch (v)
	{
	case h_A:   return "\x03-Туз"; 	case h_2:   return "Ч-2";
	case h_3:   return "Ч-3"; 		case h_4:   return "Ч-4";
	case h_5:   return "Ч-5"; 		case h_6:   return "Ч-6";
	case h_7:   return "Ч-7"; 		case h_8:   return "Ч-8";
	case h_9:   return "Ч-9"; 		case h_10:  return "Ч-10";
	case h_J:   return "Ч-Валет";	case h_Q:   return "Ч-Дама";
	case h_K:   return "Ч-Король";

	case d_A:   return "Б-Туз"; 	case d_2:   return "Б-2";
	case d_3:   return "Б-3"; 		case d_4:   return "Б-4";
	case d_5:   return "Б-5"; 		case d_6:   return "Б-6";
	case d_7:   return "Б-7";  		case d_8:   return "Б-8";
	case d_9:   return "Б-9"; 		case d_10:  return "Б-10";
	case d_J:   return "Б-Валет"; 	case d_Q:   return "Б-Дама";
	case d_K:   return "Б-Король";

	case c_A:   return "К-Туз"; 	case c_2:   return "К-2";
	case c_3:   return "К-3"; 		case c_4:   return "К-4";
	case c_5:   return "К-5"; 		case c_6:   return "К-6";
	case c_7:   return "К-7";	  	case c_8:   return "К-8";
	case c_9:   return "К-9"; 		case c_10:  return "К-10";
	case c_J:   return "К-Валет";	case c_Q:   return "К-Дама";
	case c_K:   return "К-Король";

	case p_A:   return "П-Туз"; 	case p_2:   return "П-2";
	case p_3:   return "П-3"; 		case p_4:   return "П-4";
	case p_5:   return "П-5"; 		case p_6:   return "П-6";
	case p_7:   return "П-7";  		case p_8:   return "П-8";
	case p_9:   return "П-9"; 		case p_10:  return "П-10";
	case p_J:   return "П-Валет";	case p_Q:   return "П-Дама";
	case p_K:   return "П-Король";

	default:	return "Unknown Card";
	}
}

class Koloda {
	vector<Cards> deck;
	int top;
public:
	Koloda() {
		srand((size_t)time(NULL));
		top = 0;
		for (int i = 0; i < 52; i++) { deck.push_back(s[i]); top++; }// push карт для vector-а
		random_shuffle(deck.begin(), deck.end()); // Перетасовка карт
	}

	Cards getCard() { return deck[top-- - 1]; }

	friend const char* ToString(Cards);
};