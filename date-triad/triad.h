#ifndef TRIAD_H
#define TRIAD_H
#include "header.h"

class Triad
{
protected:
	size_t first_;
	size_t second_;
	size_t third_;

public:
	Triad();
	Triad(const size_t& first, const size_t& second, const size_t& third);
	Triad(const triple_t& triple);


	size_t getFirst() const;
	size_t getSecond() const;
	size_t getThird() const;
	triple_t getTriple() const;

	void setFirst(const size_t& first);
	void setSecond(const size_t& second);
	void setThird(const size_t& third);
	void setTriple(const triple_t& triple);

	void increaseFirst();
	void increaseSecond();
	void increaseThird();
	void increaseTuple();

	string toString() const;
};
#endif
