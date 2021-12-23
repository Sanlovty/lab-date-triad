#ifndef TRIAD_H
#define TRIAD_H
#include "header.h"

class Triad
{
protected:
	int first_;
	int second_;
	int third_;

public:
	Triad();
	Triad(const int& first, const int& second, const int& third);
	Triad(const triple_t& triple);


	int getFirst() const;
	int getSecond() const;
	int getThird() const;
	triple_t getTriple() const;

	void setFirst(const int& first);
	void setSecond(const int& second);
	void setThird(const int& third);
	void setTriple(const triple_t& triple);

	void increaseFirst();
	void increaseSecond();
	void increaseThird();
	void increaseTuple();

	string toString() const;
};
#endif
