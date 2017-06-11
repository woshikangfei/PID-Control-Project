#include "PID.h"
#include <limits>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;

  // error term for P - assume very large initially
  p_error = numeric_limits<double>::max()/100;

  // error term for I - assume total area as very small as car has not started yet
  i_error = 0.0001;

  // error term for D - assume initial position of car is very far from CTE
  d_error = 0.0001;
}

void PID::UpdateError(double cte) {
   if (p_error == numeric_limits<double>::max()/100){
      p_error = cte;
  }
    

  d_error = cte - p_error;
  p_error = cte;
  i_error += cte;
}


double PID::TotalError() {
  double total_error = Kp*p_error + Kd*d_error + Ki*i_error;
  return total_error;
}


