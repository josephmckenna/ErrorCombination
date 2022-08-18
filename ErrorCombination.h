#ifndef _ERROR_COMBINATION_
#define _ERROR_COMBINATION_

#include <cmath>
#include <cstdint>
// Implementation of errors documented in
// http://www.met.rdg.ac.uk/~swrhgnrj/combining_errors.pdf

class edouble
{
public:
   double value;
   double error;

public:
   // Disable default constructor... the memory will is uninitialised
   edouble() = delete;
   // Only allow construction from integer types (integer infers counting statistics)
   explicit edouble(int8_t n)
   {
      value = n;
      error = sqrt(value);
   }
   explicit edouble(int16_t n)
   {
      value = n;
      error = sqrt(value);
   }
   explicit edouble(int32_t n)
   {
      value = n;
      error = sqrt(value);
   }
   explicit edouble(int64_t n)
   {
      value = n;
      error = sqrt(value);
   }
   explicit edouble(uint8_t n)
   {
      value = n;
      error = sqrt(value);
   }
   explicit edouble(uint16_t n)
   {
      value = n;
      error = sqrt(value);
   }
   explicit edouble(uint32_t n)
   {
      value = n;
      error = sqrt(value);
   }
   explicit edouble(uint64_t n)
   {
      value = n;
      error = sqrt(value);
   }

   explicit edouble(double n, double e)
   {
      value = n;
      error = e;
   }
   edouble(const edouble &e)
   {
      value = e.value;
      error = e.error;
   }

   // Only allow construction from integer
   // template <class T>
   edouble(double) = delete;

   bool operator==(const edouble& rhs)
   {
      if (value == rhs.value &&
         error == rhs.error)
         return true;
      return false;
   }

   // Combination functions
   edouble operator+(const edouble &rhs) const
   {
      edouble temp(
          (double)value + rhs.value,
          (double)sqrt(error * error + rhs.error * rhs.error));
      return temp;
   }

   edouble operator-(const edouble &rhs) const
   {
      edouble temp(
          value - rhs.value,
          sqrt(error * error + rhs.error * rhs.error));
      return temp;
   }

   edouble operator*(const edouble &rhs) const
   {
      edouble temp(0.0, 0.0);

      temp.value = value * rhs.value;

      const double DeltaB_Over_B = error / value;
      const double DeltaC_Over_C = rhs.error / rhs.value;

      const double e = sqrt(DeltaB_Over_B * DeltaB_Over_B + DeltaC_Over_C * DeltaC_Over_C);
      temp.error = temp.value * e;

      return temp;
   }

   edouble operator/(const edouble &rhs) const
   {
      edouble temp(0.0, 0.0);

      temp.value = value / rhs.value;

      const double DeltaB_Over_B = error / value;
      const double DeltaC_Over_C = rhs.error / rhs.value;

      const double e = sqrt(DeltaB_Over_B * DeltaB_Over_B + DeltaC_Over_C * DeltaC_Over_C);
      temp.error = temp.value * e;

      return temp;
   }

   // Multiply by constant functions
   edouble operator*(const double d) const
   {
      edouble ans(this->value, this->error);
      ans.value *= d;
      ans.error *= fabs(d);
      return ans;
   }

   edouble operator/(const double d) const
   {
      edouble ans(this->value, this->error);
      ans.value /= d;
      ans.error /= d;
      return ans;
   }

};

static edouble operator*(const double d, const edouble &rhs)
{
   // Multiply function is mutable, reuse code:
   return rhs * d;
}

static edouble operator/(const double d, const edouble &rhs)
{
   edouble temp(0.0, 0.0);
   temp.value = d / rhs.value;
   temp.error = fabs(d / (rhs.value * rhs.value)) * rhs.error;
   return temp;
}

static edouble pow(const edouble& rhs, const double exponent)
{
   edouble temp(0.0, 0.0);
   temp.value = pow(rhs.value,exponent);
   temp.error = fabs(temp.value / rhs.value) * rhs.error;
   return temp;
}

static edouble sqrt(const edouble& rhs)
{
   return pow(rhs,0.5);
}

#include <ostream>
static std::ostream &operator<<(std::ostream &os, const edouble &rhs)
{
   os << "(" << rhs.value << " +/- " << rhs.error << ")";
   return os;
}

#endif