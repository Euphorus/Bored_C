#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Race{
  int numberofLaps;
  int currentLaps;
  char firstPlaceDriverName[60];
  char firstPlaceRaceCarColor[20];
};

struct RaceCar{
  char driverName[60];
  char raceCarColor[20];
  int totalLapTime;
};

void printIntro()
{
  printf("Welcome to our main event digital race fans!\n I hope everybody has their snacks ready because we are about to begin!\n");
}


void printCountDown()
{
  printf("Racers Ready! In...\n5\n4\n3\n2\n1\nRace!\n\n");
}

void printFirstPlaceAfterLap(struct Race race)
{
  printf("After lap number %d\n", race.currentLaps);
  printf("First Place Is: %s in the %s race car\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

void printCongratulation(struct Race race)
{
  printf("Let's all congratulate %s in the %s race car for an amazing performance.\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
  printf("It truly was a great race and everybody have a goodnight!");
}

int calculateTimeToCompleteLap()
{
  int speed = (rand() % 3) + 1;
  int acceleration = (rand() % 3) + 1;
  int nerves = (rand() % 3) + 1;

  return speed + acceleration + nerves;
}

void updateRaceCar(struct RaceCar* racecar)
{
  racecar->totalLapTime += calculateTimeToCompleteLap(); 
}

void updateFirstPlace(struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2)
{
  if(raceCar1->totalLapTime <= raceCar2->totalLapTime)
  {
    strcpy(race->firstPlaceDriverName, raceCar1->driverName);
    strcpy(race->firstPlaceRaceCarColor, raceCar1->raceCarColor);
  } else {
    strcpy(race->firstPlaceDriverName, raceCar2->driverName);
    strcpy(race->firstPlaceRaceCarColor, raceCar2->raceCarColor);
  }
}

void startRace(struct RaceCar* raceCar1, struct RaceCar* raceCar2)
{
  struct Race race = {5, 0, " ", " "};

  for(int i = 0; i <= race.numberofLaps; i++)
  {
    updateRaceCar(raceCar1);
    updateRaceCar(raceCar2);
    updateFirstPlace(&race, raceCar1, raceCar2);
    printFirstPlaceAfterLap(race);
    race.currentLaps++;
  }
  printCongratulation(race);
}

int main()
{
  srand(time(0));

  printIntro();
  printCountDown();

  struct RaceCar car1 = {"Dilip", "Blue", 0};
  struct RaceCar car2 = {"Yuvraj", "Red", 0};

  startRace(&car1, &car2);


}
