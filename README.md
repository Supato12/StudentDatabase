Project created using Vim text editor on linux version: ubuntu 20.04 LTS; with g++ compiler and c++17 language.</br>


To compile project, having g++ compiler use following command:</br>
g++ -o StudentDatabase StudentDatabase.cc -Wall -Wextra -Werror -pedantic -std=c++17</br>

StudentDatabase is a program that allows user to create/load/edit database of students with their surname, faculty and average mark.</br>
Upon starting the program it loads database.txt file. If file is empty or nonexistent it runs with empty database.</br>
After that there is a menu allowing user to determine theirs actions. If user makes changes that they don't want to 
apply just exit program. Otherwise use option to save database. It then saves changes such as deleting, creating and editing student.</br>
Output file name is same as the input one - database.txt - so if you dont want to overwrite the file make sure to do a copy of your database file.</br>
If your database is quite large you can use search module by ID, surname, faculty, average mark.</br>
</br>
ID for each student is unique, so f.e if you have three records and delete the third one, the next student you add wil not have ID = 3 but = 4.</br>

Example of structure of the loaded file is in the repository but if you wish to create urself one without downloading whole repository make sure to:</br>
stick to the following structure: </br>
ID(spacebar)Surname(spacebar)Faculty(spacebar)AverageMark</br>
f.e </br>
1 Nowak MathsAndPhysics 3.0</br>
2 Kawasaki ComputerScience 4.75 </br>
...</br>

----------------------------------------------------------------------------------

The project bases on structure stored in vector. It is fairly easily expandable and flexible to adjust to your own database.</br>
Comments in this are unnecessary as the methods and variables states what their purpose is themselves.




