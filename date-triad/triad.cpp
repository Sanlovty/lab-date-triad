#include "triad.h"

Triad::Triad() :
	first_(int()),
	second_(int()),
	third_(int())
{
}

Triad::Triad(const int& first,
             const int& second,
             const int& third) :
	first_(first),
	second_(second),
	third_(third)
{
}

Triad::Triad(const triple_t& triple) :
	first_(get<0>(triple)),
	second_(get<1>(triple)),
	third_(get<2>(triple))
{
}

int Triad::getFirst() const
{
	return first_;
}

int Triad::getSecond() const
{
	return second_;
}

int Triad::getThird() const
{
	return third_;
}

triple_t Triad::getTriple() const
{
	return triple_t(first_, second_, third_);
}

void Triad::setFirst(const int& first)
{
	first_ = first;
}

void Triad::setSecond(const int& second)
{
	second_ = second;
}

void Triad::setThird(const int& third)
{
	third_ = third;
}

void Triad::setTriple(const triple_t& triple)
{
	*this = Triad(triple);
}

void Triad::increaseFirst()
{
	first_++;
}

void Triad::increaseSecond()
{
	second_++;
}

void Triad::increaseThird()
{
	third_++;
}

void Triad::increaseTuple()
{
	first_++;
	second_++;
	third_++;
}

string Triad::toString() const
{
	return "Triad {\n"
		" first: " + to_string(first_) +
		" second: " + to_string(second_) +
		" third: " + to_string(third_) +
		+"}";
}
