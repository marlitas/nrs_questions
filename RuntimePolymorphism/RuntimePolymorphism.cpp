#include <iostream>
#include <map>
#include <string>

class ParentSpider{
  public:
    void parse(std::map<char, std::string> response)
    {
      std::cout << "parent" << std::endl;
      std::cout << response['a'] << std::endl;
      std::cout << response['b'] << std::endl;
    };
};

class ChildSpider: public ParentSpider{

  public:
    //Same function as parent but with added functionality
    void parse(std::map<char, std::string> response)
    {
      //The parent function can be called inside the child function to add onto the parent functionality
      //This allows us to dry up the code providing greater legibility, and efficiency
      ParentSpider::parse(response);
      std::cout << "child" << std::endl;
      std::cout << response['a'] + ' ' + response['b']<< std::endl;
    };
};

//The functionality provided here is an incredibly simplified example of what the spiders I've built can do, but it does provide insight into how runtime polymorphism works.
int main(){
  std::map<char, std::string> response;
  response['a']="foo";
  response['b']="bar";

  ParentSpider parent;
  parent.parse(response);

  ChildSpider child;
  child.parse(response);

  return 0;
}

//When the code runs the parent parse function returns:
// parent
// foo
// bar
//The child parse function returns:
// parent
// foo
// bar
// child
// foo bar