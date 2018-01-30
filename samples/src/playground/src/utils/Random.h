#ifndef RANDOM_H_INCLUDED
#define RANDOM_H_INCLUDED

#include <cstdint>

namespace pg {


/// The underlying generator is the new Park-Miller minimum standard linear 
/// congruential generator from 1993, which is slightly faster than
/// the original version.

// seed the generator with a non-deterministic seed provided by the operating system
void randomize();

void seed(unsigned int seed);

/// \brief Get a random int32 in [ a, b ].
std::int32_t randi(std::int32_t a, std::int32_t b);

/// \brief Get a random float in [ a, b ).
float randf(float a, float b);

/// \brief Get a random float in [ 0, 1 ).
float randf();

/// \brief Get a random double in [ a, b ).
double randd(double a, double b);

/// \brief Ger a random number in [ 0, 1 ).
double randd();
}

#endif // RANDOM_H_INCLUDED
