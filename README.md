# Warriors-of-Light
A simple text based console C++ game

As you look at this code, please remember that I coded this in my spare time in one weekend.

Warriors of Light:

The basic premise of the game is simple. There are 3 classes of warriors. The Berserker is a warrior that draws
power from the red spectrum of light and is able to do up to double the amount of normal damage. The Tank uses the
green spectrum of light and uses it to generate extreme body density giving him double the hp of a normal warrior.
Finally, the Medic draws from the blue spectrum of light and is able to heal himself or his teammates (up to 5 hp
per round).

The gameplay is simple. There are 2 players and each player has a team with 5 warriors (2 Berserkers, 2 Tanks, 
and 1 medic). The game is divided into rounds which consists of 2 battles. For each battle, each player picks one
of the warriors to fight and the battle ends when one of the warriors is defeated and removed from the team. Play
continues until one player is out of warriors causing the other player to be declared the victor. After each battle,
if the player has a medic, that player can choose to heal one or more of the warriors on the team. The medic is only 
allowed to generate 5 hp of healing per round in total (which has 2 battles). The hp healing resets at the beginning 
of each round and is available at the end of the first battle.


This program highlights the power of inheritance and polymorphism. The base class in the code is Warrior.
The 3 derived classes are Berserker, Tank, and Medic. This setup is useful in this case as it allows me to
essentially store objects from 3 different classes in the same vector by storing them as shared pointers to 
the base class Warrior. In addition, the polymorphism creeps in as the virtual classes defined in Warrior.h and
and overridden in the derived classes allow me to make the function call to the base pointer and receive the 
functionality of the overridden function in the derived class automatically. For example, the Berserker can do up 
to twice the damage that a normal warrior can do. This is achieved with the virtual calculateDamage function. When 
called from a base pointer that points to a Berserker object, it calls the calculateDamage function from the Berserker
class instead of the function in the warrior class, allowing the Berserker to do up to 10 hp of damage instead of only 5.
I also use the virtual function resetTotalHeal to reset the hp healing points of the medic at the beginning of each round.

You will also notice that I added a Game class which basically handles the functionality of the game flow and contains
the main game loop in the run function. This of course is necessary so that the main function is not all cluttered up
with spaghetti code and instead is only 4 lines of code. In case you don't see it, WarriorsOfLight.cpp is the file
that contains the main function. The Game class also contains 2 instances of the Player class which has useful data for
player1 and player2 as well as helpful methods for game functionality.


Also attached is a pdf file called notes which are a scanned copy of the brainstorming notes that I wrote down before
coding this project. If you have any specific questions about my design decisions, code usage, or problems I encountered,
please feel free to contact me at ricksunstrom@gmail.com

Speaking of problems that I encountered, let me be real with you and talk about them. The first major problem that I encountered
was that I tried to achieve polymorphism by storing the 5 different derived class objects in a vector of warrior objects. This compiled
and worked just fine but of course, never triggered the overidden virtual functions in the derived classes, just the implentation in the
base warrior class. I then tried to use a vector of raw pointers to Warrior objects (without dynamically allocating the memory) causing
all kinds of problems when I tried to access data or call functions from the pointers in the vector. Finally, I just decided to give up 
on raw pointers and new and delete and tried to use unique_pointers. I had too many issues iterating through the vector especially when 
removing an object while iterating so I switched to shared_pointers instead and everything was golden. Those were the major issues that I 
had. Everything else was just little things to tweak logic or setup-wise here and there.

Again if you have any questions or comments, please feel free to reach out to me at ricksunstrom@gmail.com

