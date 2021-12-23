#ifndef DATE_H
#define DATE_H
#include <tuple>
#include <string>

#include "triad.h"

class Date : public Triad
{
	const char stringSeparator_ = '.';
	static const size_t defaultDay_ = 1;
	static const size_t defaultMonth_ = 1;
	static const size_t defaultYear_ = 1970;
	const size_t monthDays_[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


	size_t roundBy_(const size_t& value, const size_t& bound) const;
	static bool isLeapYearMethod_(const size_t& year);

	void roundDays_();
	size_t toDaysMethod_(const Date& date) const;
	Date daysToDate_(const size_t& days) const;

public:
	Date();
	Date(const size_t& day, const size_t& month, const size_t& year);

	size_t getDay() const;
	size_t getMonth() const;
	size_t getYear() const;
	triple_t getDate() const;

	void setDay(const size_t& day);
	void setMonth(const size_t& month);
	void setYear(const size_t& year);
	void setDate(const size_t& day, const size_t& month, const size_t& year);


	void increaseFirst();
	void increaseSecond();
	void increaseThird();
	void increaseTuple();

	void increaseDateByN(const size_t& n);

	size_t toDays() const;
	bool isLeapYear() const;
	size_t differenceBetween(Date date) const;
	Date dateBeforeByDays(const size_t& days) const;
	Date dateAfterByDays(const size_t& days) const;

	Date& operator=(const Date& other);

	string toString() const;
};

#endif
