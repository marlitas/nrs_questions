# Answers to NetherRealm Studios Questions

### How many hours a week would you be available to commit to?
- 25 hours would be ideal. 30 is doable, but the absolute maximum I can commit to.

### Do you require visa sponsorship?
- No.

### Can you describe in detail and your own words how to accomplish runtime polymorphism in C++ with code examples?
- Runtime polymorphism gives us the ability to use OOP of inheritance. This means that instead of the program choosing which function to call at compile time, the program chooses the function dynamically based on rules of inheritance. The most clear example of this is when there is a Parent Class( or base class) with children. The child will inherit all the functionality of the parent class, plus have it's own functionality if desired. Runtime polymorphism occurs when both the parent and the child class have a function with the same name. In this case function overriding occurs and the child's function will be called over the parents. The code example I'm providing comes from a web scraping project I'm currently working on at my internship. There are many sites that need to be scraped, resulting in a large number of spiders that will need both customized functionality as well as global functionality. The best thing to do to solve this dilemma is to create a parent spider class, that the child spiders can then inherit from. For clarity: spiders crawl through websites to find content according to the CSS/HTML structure of the site.
- [Code Example](https://github.com/marlitas/nrs_questions/blob/main/RuntimePolymorphism/RuntimePolymorphism.cpp)

###  Can you read the following code and explain to us the purpose of foo?  Are there bugs you’d fix or ways you would suggest to improve foo?  Please send us your improved/corrected version.
- The function foo is sorting a vector of three dimensional points based on a modified standard deviation. I say modified, because standard deviation generally involves dividing by the average, but that calculation is not included in this function. 
- The first thing that stood out to me in this function was legibility. A while loop with a bang operator is always so tricky to read, and can get confusing when you're trying to keep up with what the function is doing. I initially changed the bool done variable to a bool active variable, so that we could say while(active), making the while loop slightly easier to digest.
- One note to add onto this code I submitted is that I did have a tough time testing that the vector was in fact switching properly. I believe there is something I'm not understanding about the swap function and how vector variables point to their content that is holding me back, but the function seemed to work properly when I printed to the terminal. I tried to research more about why this was happening, but ran out of time to properly implement testing.
- [Improved/Corrected Code](https://github.com/marlitas/nrs_questions/blob/main/foo/foo.cpp)

### Can you implement IsValidPlayer in the example below for us in C++?
- [Code Implementation](https://github.com/marlitas/nrs_questions/blob/main/ValidPlayer/IsValidPlayer.cpp)

### Takeaways
- Really diving into what it means to have a statically typed compiled language forced me to think about the code I was writing in a very specific way. I have had to work with Typescript a bit in the past, and this felt similar to that in some ways. Really thinking in depth about what specifically my variables are allowed me to look past some of the "magic" that python and ruby provides. It gave me a greater understanding of what the code is actually doing. 
- I really wanted to approach this from a TDD perspective. I was sort of able to by using assert statements, but I did try to learn Boost.test in time for this challenge, and it was just beyond my bandwidth for the time I had available. I hope to dive into the C++ testing frameworks a bit more in the future.
