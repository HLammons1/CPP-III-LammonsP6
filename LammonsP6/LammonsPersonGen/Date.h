//Hayden Lammons
//HLammons1@cnm.edu
//LammonsP1

// Date.h

#ifndef _DATE_H
#define _DATE_H

#include <string>
#include <chrono>
using namespace std;
using namespace chrono;

class Date
{
	private:
			int month{ 1 }, day{ 1 }, year{ 1970 };
			int dayOfYear{0};
			string description;
			year_month_day ymd;
			bool bLeap{ NULL };

	public:
			Date();
			Date(int m, int d, int y, string desc);
			void SetDate(int m, int d, int y, string desc);
			void SetDesc(string d){ description = d; }
			//void SetYMD();
			int CalcAge();


			string GetFormattedDate();
			
			void DetermineLeapYear();
			void CalcDayOfYear();
			int GetYear(){ return year;}
			int GetMonth(){ return month;}
			int GetDay(){ return day;}
			year_month_day GetYearMonthDay() const { return ymd; }
			int operator - (const Date& other) const;

};

#endif