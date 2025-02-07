// This header file is to do the math to transfer between cartesians coordinates and the Scara angles
// Inputting the desired cartesian coordinates will output the two angles or NAN if outside the area
#define A1 80
#define B1 100
#define C1 80
#define D1 100
#define B 50

bool CartesianTransfer(float x, float y, float& theta, float& phi) {
  // Calculates inital intermediate arm lengths
  float s1 = sqrt(pow(x,2)+pow(y,2));
  float s2 = sqrt(pow(x-B,2)+pow(y,2));
  
  //check if within the range of the arms
  // First check ensures that the robot will not cross the inner singularity
  // Second and Third ensure that the point is within the reach of both arms

  if ( (y < 28) || (s1 >= A1+B1) || (s2 >= C1+D1) ) {
    return false;
  }

  //Joint A
  float ta3 = atan2(y,x);
  float ta2 = CosineLaw(s1,A1,B1);
  float ta1 = 3.14159 - ta2-ta3;

  //Joint B
  float tb1 = CosineLaw(B1,A1,s1);

  //Joint C
  float tc1 = 3.14159 - atan2(y,x-B);
  float tc2 = CosineLaw(C1,s2,D1);
  float tc3 = 3.14159 - tc1 - tc2;

  //Joint D
  float td1 = CosineLaw(D1,C1,s2);

  theta = ta2 + ta3;
  phi = tc3;
  
  return true;
};

float CosineLaw( float a, float, b, float c) {
  return acos( ( pow(a,2) + pow(b,2) - pow(c,2) ) / (2 * a * b));
}
