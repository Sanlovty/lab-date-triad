#include "Date.h"
#include "Date.h"


size_t Date::roundBy_(const size_t& value, const size_t& bound) const
{
	return value % bound;
}

void Date::roundDays_()
{
	if (first_ > monthDays_[second_ - 1])
	{
		if (second_ == 2 && isLeapYear())
		{
			first_ = monthDays_[second_ - 1] + 1;
			return;
		}
		first_ = monthDays_[second_ - 1];
	}
}

size_t Date::toDaysMethod_(const Date& date) const
{
	size_t days = 0;
	for (size_t y = 1; y <= date.getYear(); y++)
	{
		if (isLeapYearMethod_(y))
		{
			days += 366;
		}
		else
		{
			days += 365;
		}
	}
	for (size_t m = 1; m < date.getMonth(); m++)
	{
		if (m == 2 && isLeapYearMethod_(date.getYear()))
		{
			days += monthDays_[m - 1] + 1;
		}
		else
		{
			days += monthDays_[m - 1];
		}
	}
	for (size_t d = 1; d <= date.getDay(); d++)
	{
		days++;
	}
	return days;
}

Date Date::daysToDate_(const size_t& days) const
{
	size_t daysCopy = days;
	size_t years = 0;
	size_t months = 1;
	bool yearsEnough = false;
	bool monthsEnough = false;

	while (!yearsEnough && daysCopy >= 365)
	{
		if (isLeapYearMethod_(years))
		{
			if (daysCopy > 366)
			{
				years++;
				daysCopy -= 366;
			}
			else
			{
				yearsEnough = true;
			}
		}
		else
		{
			if (daysCopy > 365)
			{
				years++;
				daysCopy -= 365;
			}
			else
			{
				yearsEnough = true;
			}
		}
	}
	while (!monthsEnough)
	{
		if (months == 2 && isLeapYearMethod_(years))
		{
			if (daysCopy > monthDays_[months - 1] + 1)
			{
				months++;
				daysCopy -= monthDays_[months - 1] + 1;
			}
			else
			{
				monthsEnough = true;
			}
		}
		else
		{
			if (daysCopy > monthDays_[months - 1])
			{
				daysCopy -= monthDays_[months - 1];
				months++;
			}
			else
			{
				monthsEnough = true;
			}
		}
	}
	if (daysCopy == 0)
	{
		daysCopy = 1;
	}
	if (months == 0)
	{
		months = 1;
	}
	if (years == 0)
	{
		years = 1;
	}
	return Date(daysCopy, months, years);
}

Date::Date()
{
	first_ = defaultDay_;
	second_ = defaultMonth_;
	third_ = defaultYear_;
}

Date::Date(const size_t& day, const size_t& month, const size_t& year)
{
	setYear(year);
	setMonth(month);
	setDay(day);
}

size_t Date::getDay() const
{
	return first_;
}

size_t Date::getMonth() const
{
	return second_;
}

size_t Date::getYear() const
{
	return third_;
}

triple_t Date::getDate() const
{
	return triple_t(first_, second_, third_);
}

void Date::setDay(const size_t& day)
{
	if (day == 0)
	{
		first_ = defaultDay_;
	}
	else
	{
		first_ = day;
	}

	roundDays_();
}

void Date::setMonth(const size_t& month)
{
	second_ = roundBy_(month, 13);
	if (second_ == 0)
	{
		second_ = defaultMonth_;
	}
	roundDays_();
}

void Date::setYear(const size_t& year)
{
	if (year == 0)
	{
		third_ = defaultYear_;
	}
	else
	{
		third_ = year;
	}
	roundDays_();
}

void Date::setDate(const size_t& day, const size_t& month, const size_t& year)
{
	*this = Date(day, month, year);
}

void Date::increaseFirst()
{
	setFirst(first_ + 1);
}

void Date::increaseSecond()
{
	setSecond(second_ + 1);
}

void Date::increaseThird()
{
	setThird(third_ + 1);
}

void Date::increaseTuple()
{
	setThird(third_ + 1);
	setSecond(second_ + 1);
	setFirst(first_ + 1);
}

bool Date::isLeapYearMethod_(const size_t& year)
{
	return (year % 100 == 0) ? (year % 400 == 0) : (year % 4 == 0);
}

void Date::increaseDateByN(const size_t& n)
{
	*this = daysToDate_(toDays() + 1 + n);
}

size_t Date::toDays() const
{
	return toDaysMethod_(*this);
}


Date& Date::operator=(const Date& other)
{
	if (this == &other)
	{
		return *this;
	}
	first_ = other.first_;
	second_ = other.second_;
	third_ = other.third_;
	return *this;
}

string Date::toString() const
{
	string day = first_ < 10 ? '0' + to_string(first_) : to_string(first_);
	string month = second_ < 10 ? '0' + to_string(second_) : to_string(second_);

	return "Date {\n"
		" day: " + day +
		" month: " + month +
		" year: " + to_string(third_) +
		+"}";
}
