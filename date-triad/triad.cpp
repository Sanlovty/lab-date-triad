#include "triad.h"

Triad::Triad() :
	first_(size_t()),
	second_(size_t()),
	third_(size_t())
{
}

Triad::Triad(const size_t& first,
             const size_t& second,
             const size_t& third) :
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

size_t Triad::getFirst() const
{
	return first_;
}

size_t Triad::getSecond() const
{
	return second_;
}

size_t Triad::getThird() const
{
	return third_;
}

triple_t Triad::getTriple() const
{
	return triple_t(first_, second_, third_);
}

void Triad::setFirst(const size_t& first)
{
	first_ = first;
}

void Triad::setSecond(const size_t& second)
{
	second_ = second;
}

void Triad::setThird(const size_t& third)
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
