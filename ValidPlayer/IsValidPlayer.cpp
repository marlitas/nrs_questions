#include <iostream>
#include <assert.h>
#include <stdio.h>

const char *PlayerNames[] =
{
  "Scorpion",
  "SubZero",
  "LiuKang"
};
 

bool IsValidPlayer( const char* player )
{
  int size = sizeof(PlayerNames) / sizeof(PlayerNames[0]);

  for (int i = 0; i < size; i++)
  {
    if (player == PlayerNames[i])
    {
      return true;
    }
  }
  return false;
}

void TestValidPlayer()
{
  assert(IsValidPlayer("Scorpion") == true);

  assert(IsValidPlayer("Nope") == false);
}

int main()
{
  TestValidPlayer();
  return 0;
}