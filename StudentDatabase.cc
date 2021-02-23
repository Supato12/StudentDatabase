#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include <cstdlib>

struct Student
{
	uint16_t id;
	std::string surname;
	std::string faculity;
	float averageOutcome;
};

bool loadDatabase(std::vector<Student> &students);
void manageStudents(std::vector<Student> &students);
void showMenu();
void showStudent(const std::vector<Student> &students, size_t i);
void showDatabase(const std::vector<Student> &students);
void addStudent(std::vector<Student> &students);
void deleteStudent(std::vector<Student> &students);
void searchStudent(const std::vector<Student> &students);
void editStudent(std::vector<Student> &students);
void saveDatabase(const std::vector<Student> &students);

template <typename T> T choiceGetter();

int main()
{   
    std::vector<Student> students;
    if(loadDatabase(students))
    {
	    std::cout << "\n Database loaded successfully\n"; 
    }
    else
    {
        std::cout << "\n Database loading failed or file not found\n";
    }
    std::cout << " Starting program.. \n";
    manageStudents(students);
}

void manageStudents(std::vector<Student> &students)
{
    showMenu();
    auto choice = choiceGetter<int>();
    switch (choice)
    {
        case 1:
            showDatabase(students);
            break;
	    case 2:
            addStudent(students);
		    break;
	    case 3:
            deleteStudent(students);
            system("clear");
            break;
        case 4:
            searchStudent(students);
            break;
        case 5:
            editStudent(students);
            break;
        case 6:
            saveDatabase(students);
	        std::cout << "\n Database saved...\n";
            break;
        case 7:
            exit(EXIT_SUCCESS);
            break;
    }
    manageStudents(students);
}

void showMenu()
{
	std::cout << "\n 1. Show database";
	std::cout << "\n 2. Add student";
	std::cout << "\n 3. Delete Student";
	std::cout << "\n 4. Search for Student(after: ID, faculty surname or Average mark)";
	std::cout << "\n 5. Edit student";
	std::cout << "\n 6. Save Database";
	std::cout << "\n 7. Exit \n\n";
	std::cout << "What do you want to do?: ";
}

template <typename T>
T choiceGetter()
{
    T choice;
    while (!(std::cin >> choice))
    {
        std::cout << "\n Wrong value, try again:";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return choice;
}

void addStudent(std::vector<Student> &students) 
{
	do
	{
		system("clear");   
        static uint16_t id;
        if(students.empty())
        {
            id = 1;
        }
        else 
        {
            id = students.back().id + 1;
        }
        Student student;
        student.id = id++;
        std::cout << "\n Surname: "; 
        std::cin >> student.surname;
        std::cout << "\n Faculty: "; 
        std::cin >> student.faculity;
        std::cout << "\n Average mark: "; 
        std::cin >> student.averageOutcome;
		students.push_back(student);
        std::cout << "\n Student has been added....";
        std::cout << "\n To add another student pick: 1, to go back pick: 2(or any other number): ";
	} while (choiceGetter<int>() == 1);
    system("clear");
    manageStudents(students);
}

void showStudent(const std::vector<Student> &students, size_t i)
{
    std::cout << "\n (" << i+1 << ")";
    std::cout << "\n ID: " << students.at(i).id;
    std::cout << "\n Surname:  " << students.at(i).surname;
    std::cout << "\n Faculty: " << students.at(i).faculity;
    std::cout << "\n Average mark: " << students.at(i).averageOutcome;
    std::cout << "\n---------------------------------------\n";
}

void showDatabase(const std::vector<Student> &students)
{
	for (size_t i = 0; i < students.size(); ++i)
	{
        showStudent(students, i);
	}
}

void deleteStudent(std::vector<Student> &students)
{
	do
	{   
        system("clear");
        showDatabase(students);
		std::cout << "Which record do you want to delete?:  ";
        auto choiceDel = choiceGetter<int>();
		auto it = students.begin() + choiceDel - 1; 
        students.erase(it);
		system("clear");
		showDatabase(students);
		std::cout << "\n Student deleted...\n Pick 1 to delete another student, pick 2 to end: "; 
    } while (choiceGetter<int>() == 1);
	system("clear");
}

void searchStudent(const std::vector<Student> &students)
{
	do
	{
		system("clear");
        std::cout << "\n Search by:";
		std::cout << "\n 1. ID";
		std::cout << "\n 2. Surname";
		std::cout << "\n 3. Average Mark";
		std::cout << "\n 4. Faculty";
        std::cout << "\n 5. Go back";
		std::cout << "\n Pick 1 - 5: ";
        auto howSearch = choiceGetter<int>();
		switch (howSearch)
		{
		case 1:
        {
			std::cout << "\n\n Give id: "; 
            auto searchID = choiceGetter<int>();
			for (size_t i = 0; i < students.size(); ++i)
			{
				if (students.at(i).id == searchID)
				{
                    showStudent(students, i);
				}
			}
        }
			break;
		case 2:
        {
			std::cout << "\n Give surname: "; 
            auto searchSurname = choiceGetter<std::string>();
			for (size_t i = 0; i < students.size(); ++i)
			{
				if (students.at(i).surname == searchSurname)
				{
                    showStudent(students, i);
				}
			}
        }
			break;
		case 3:
        {
			std::cout << "\n Give average mark: "; 
            auto searchAvgmark = choiceGetter<float>();
			for (size_t i = 0; i < students.size(); ++i)
			{
				if (students.at(i).averageOutcome == searchAvgmark)
				{
                    showStudent(students, i);
				}
			}
        }
			break;
		case 4:
        {
			std::cout << "\n Give faculty: "; 
            auto searchFaculty = choiceGetter<std::string>();
			for (size_t i = 0; i < students.size(); ++i)
			{
				if (students.at(i).faculity == searchFaculty)
				{
                    showStudent(students, i);
				}
			}
        }
			break;
        case 5:
            std::cout << "\n Going back.. \n";
            break;
		}
		std::cout << "\n To search again pick 1, to go back pick 2: "; 
	} while (choiceGetter<int>() == 1);
	system("clear");
}

void editStudent(std::vector<Student> &students)
{
	do
	{
        showDatabase(students);
		std::cout << "\n Whose data do you want to edit(pick ID)";
        auto choiceID = choiceGetter<int>();
		system("clear");
		for (size_t i = 0; i < students.size(); ++i)
		{
			if (students.at(i).id == choiceID)
            {
                showStudent(students, i);
				std::cout << "\n 1 Edit surname, 2 Edit faculty, 3 Edit average mark: ";
                auto whatEdit = choiceGetter<int>();
				switch (whatEdit)
				{
				case 1:
                {
					std::cout << "\n Give new surname: "; 
                    auto newSurname = choiceGetter<std::string>();
					students.at(i).surname = newSurname;
					std::cout << "\n Surname has beed changed.";
                }
					break;
				case 2:
                {
					std::cout << "\n Give new faculty: "; 
                    auto newFaculty = choiceGetter<std::string>();
					students.at(i).faculity = newFaculty;
					std::cout << "\n Faculty has been changed";
				}
                break;
				case 3:
				{
                    std::cout << "n Give new average mark: ";
                    auto newAverageOutcome = choiceGetter<float>();
					students.at(i).averageOutcome = newAverageOutcome;
					std::cout << "\n Average mark has been changed.";
                }
					break;
				}
			}
		}
		std::cout << "\n 1, to edit again, 2 to go back.: ";
	} while (choiceGetter<int>() == 1);
	system("clear");
}

bool loadDatabase(std::vector<Student> &students)
{
	std::ifstream file("database.txt", std::ios::in);
	if (!file)
	{
        return false;
	}
    Student student;
	while (file >> student.id)
	{
        file >> student.surname;
        file >> student.faculity;
        file >> student.averageOutcome;
		students.push_back(student);
	}
	file.close();
    return true;
}

void saveDatabase(const std::vector<Student> &students)
{
	std::ofstream file("database.txt", std::ios::out);
	for (size_t i = 0; i < students.size(); ++i)
	{
		file << students.at(i).id << " " 
             << students.at(i).surname << " "
             << students.at(i).faculity << " " 
             << students.at(i).averageOutcome << '\n';
	}
	file.close();
}
