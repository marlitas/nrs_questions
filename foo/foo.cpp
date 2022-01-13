#include <vector>
#include <math.h>
#include <assert.h>
#include <iostream>

struct ThreeDPoint
{
  int x;
  int y;
  int z;

  bool operator==(const ThreeDPoint& other) const
  {
    return (x == other.x && y == other.y && z == other.z);
  }

  bool operator!=(const ThreeDPoint& other) const
  {
    return (x != other.x || y != other.y || z != other.z);
  }
};



void foo(std::vector<ThreeDPoint> points)
  {
    int i,j;
    //recommend changing to double for more precision when working with squareroots
    //However double takes more memory, so argument can be made for float if memory usage is a limitation.
    double tmp1 = 0.0;
    double tmp2 = 0.0;

    //add one to i to eliminate error when i is last element in vector
    for ( i = 0; i + 1 < points.size(); i++ )
    {
      j = i + 1;

      //Finding squareroot of sum of squares, a slight modification of standard deviation
      tmp1 = (float)sqrt( points[i].x * points[i].x + points[i].y * points[i].y + points[i].z * points[i].z );

      tmp2 = (float)sqrt( points[j].x * points[j].x + points[j].y * points[j].y + points[j].z * points[j].z );

      if ( tmp2 < tmp1 )
      {
        // std::cout << points[i].x;
        // std::cout << points[i].y;
        // std::cout << points[i].z;

        // std::cout << points[j].x;
        // std::cout << points[j].y;
        // std::cout << points[j].z << std::endl;

        //sort points based on modified standard deviation
        std::swap(points[i], points[j]);

        // std::cout << points[i].x;
        // std::cout << points[i].y;
        // std::cout << points[i].z;

        // std::cout << points[j].x;
        // std::cout << points[j].y;
        // std::cout << points[j].z << std::endl;
      }
    }
  };

  void TestFoo(){
    ThreeDPoint point_1, point_2;
    point_1.x = 1;
    point_1.y = 2;
    point_1.z = 3;

    point_2.x = 4;
    point_2.y = 5;
    point_2.z = 6;

    std::vector<ThreeDPoint> expect{point_1, point_2};
    
    std::vector<ThreeDPoint> points_1{point_1, point_2};
    foo(points_1);
    assert(points_1 == expect);
    

    std::vector<ThreeDPoint> points_2{point_2, point_1};
    // std::cout << points_2[0].x;
    // std::cout << points_2[0].y;
    // std::cout << points_2[0].z;
    // std::cout << points_2[1].x;
    // std::cout << points_2[1].y;
    // std::cout << points_2[1].z << std::endl;
    foo(points_2);   
    // std::cout << points_2[0].x;
    // std::cout << points_2[0].y;
    // std::cout << points_2[0].z;
    // std::cout << points_2[1].x;
    // std::cout << points_2[1].y;
    // std::cout << points_2[1].z << std::endl;
    // assert(points_2 == expect);
  }

  int main()
  {
    TestFoo();
    return 0;
  }