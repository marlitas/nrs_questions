//Runtime polymorphism gives us the ability to use OOP of inheritance. This means that instead of the program choosing which function to call at compile time, the program chooses the function dynamically based on rules of inheritance. 
//The most clear example of this is when there is a Parent Class( or base class) with children. The child will inherit all the functionality of the parent class, plus have it's own functionality if desired. Runtime polymorphism occurs when both the parent and the child class have a function with the same name. In this case function overriding occurs and the child's function will be called over the parents.
//The code example I'm providing comes from a webscraping project I'm currently working on in my internship. There are many sites that need to be scraped, meaning that we will have a large number of spiders (crawl through the html response) that will need both customized functionality as well as global functionality. The best thing to do to solve this dilemma is to create a parent spider class, that the child spiders can then inherit from. 

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