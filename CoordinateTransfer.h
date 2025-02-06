// This header file is to do the math to transfer between cartesians coordinates and the Scara angles
// Inputting the desired cartesian coordinates will output the two angles or NAN if outside the area
#define A1 20
#define B1 20
#define C1 20
#define D1 20
#define B 20

bool CartesianTransfer(int x, int y, int& theta, int& phi) {
  // Calculates inital intermediate arm lengths
  float s1 = sqrt(pow(x,2)+pow(y,2));
  float s2 = sqrt(pow(x-B,2)+pow(y,2));
  
  //check if within the range of the arms
  // First check ensures that the robot will not cross the inner singularity
  // Second and Third ensure that the point is within the reach of both arms

  if ( (y < 5) || (s1 >= A1+B1) || (s2 >= C1+D1) ) {
    return false;
  }

  ta3 = atan2(x,y);
  tc1 = atan2(x-B,y);
  
  
  return true;
};

inline float CosineLaw( float a, float, b, float c) {
  return acos( ( pow(a,2) + pow(b,2) - pow(c,2) ) / (2 * a * b));
}
