// The goal of this function is to run until the homing position has been determined and then return to the main code lines.

bool Homing(int direction = 1, int steps, AccelStepper A, int HES_Pin) {
  int HighA, HighB;
  int phase = 0;
  //Phase 0: Hunting
  //Phase 1: Tracking
  //Phase 2: Aiming

  // The duration of this phase is to rapidly find the magnetic zone of the HES in a controlled fashion
  // Full steps are used as the HES is lined up to one of the full steps.
  // It starts by turning to sweep the behind the arm and then does a full rotation to hunt for the magnetic zone.
  // If it detects anything, it records it's location and moves into Phase 1, Tracking. 
  // If nothing is found, it returns an error such that 
  Phase0:

  if (HES_pin) { goto Phase1; };

  direction *= -1;
  for ( int i = 0; i++; i<steps) {
  A.step(direction);
    if ( HES_pin ) { 
      goto Phase1;
    };
  }

  direction *= -1;
  for (int i = 0; i++; i < 200) {
    A.step(direction);
    if (HES_pin) {
      goto Phase1;
  }
  return false;

  //This phase is triggered by detecting the HES magnetic field.
  //during this phase, the goal is to find the opposing edge of the field, when HES_pin drops low again.
  // This will let the uC know two boundaries to study between.
  Phase1:

  while ( HES_PIN ) { A.step(direction); }

  // This phase begins when there is an edge detected in phase 2 and we move in direction of the edge from phase 1
  // Microstepping is enabled at this point to being machine usage.
  Phase2:
  
  direction *= -1;
  A.Microstepping();

  while (! HES_pin) { A.step(direction); }:
  HighA = A.currentPosition();
  
  while ( HES_PIN ) { A.step(direction); };
  HighB = A.currentPosition();

  A.moveTo(int (HighA+HighB)/2);
  A.setCurrentPostition();
  
  
}
