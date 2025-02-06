// This header file is to do the math to transfer between cartesians coordinates and the Scara angles
// Inputting the desired cartesian coordinates will output the two angles or NAN if outside the area
#define A1 20
#define A2 20
#define B1 20
#define B2 20
#define Base 20

int CartesianTransfer(int x, int y, int& theta, int& phi) {
  //check if within the range of the arms
  // First check ensures that the robot will not cross the inner singularity
  // Second and Third ensure that the point is within the reach of both arms
  if ( (y > 5) && (x^2 + y^2 <= (A1+A2)^2) && (x^2 + y^2 <= (B1+B2)^2) ) {
    return 0;
  }

  return theta;
};
