#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <fstream>

using namespace std;

enum QueryType { variable, text };

struct Query
{
	QueryType type;
//	string data;
};

string print_to_console(string line)
{
	int first = line.find("show<");
	int last = line.find(">", first);
	if (first != string::npos) // if !="show<"
	{
		return line.substr(first + 5, last - first - 5); //chgitem inchi 5, orenqov piti 1 liner
	}
	else return "";
}

std::map <string, string> for_integer; // both are strings b'couse couldn't change value to int static_cast<int>(value) is not working

void declere_integer(string line) // kuzenayi map_@ veradardznel, bayc chkaroxaca
{
	string name = "";
	string value = "";
	bool isAlreadyDecleared = false;
	bool isAlreadyDecleared2 = false;
	// num x<4> // der menak mi taranoc popoxakan kara lini name.lenght chi ashxatum
	int num = line.find("num ");
	int last1 = line.find(">", num);
	int for_name_lenght = line.find("<", num);
	isAlreadyDecleared2 = false;
	if (num != string::npos) /// ete gtel es
	{
		
		name = line.substr(num + 4, last1 - num - 6); //x
		value = line.substr(num + 6, last1 - num - 6);//4

		if (for_integer.find(name) != for_integer.end())
		{
			cout << "ERROR:: Variable has already been decleared";
			return;
		}
		else
		{
			isAlreadyDecleared = true;
			for_integer.insert({ name, value });
		}
	
		isAlreadyDecleared2 = true;
	}
	isAlreadyDecleared = false;

	if (isAlreadyDecleared == false && isAlreadyDecleared2 == false)
	{
		cout << endl << endl << "map is " << endl; // temprary
		for (std::map<string, string>::iterator it = for_integer.begin(); it != for_integer.end(); ++it)
		{
			int first = line.find(it->first);
			int last = line.find(">", first);
			if (first != string::npos)
			{
				it->second = line.substr(first + 2, last - first - 1); // verjin nshan@ chi hanum cuyc a talis 8>
			}

			std::cout << it->first << " => " << it->second << '\n'; //temprary
		}
	}

}

int main()
{
#pragma region read by char-char
	//std::ifstream my_file("hello.nv", std::ifstream::in);

	//char one_symbol = my_file.get();
	//string one_line = "";
	//while (my_file.good())
	//{
	//	one_symbol = my_file.get();
	//	one_line += one_symbol;
	//}
	////cout << one_line;
	//unsigned first = one_line.find("show<");
	//unsigned last = one_line.find(">", first);
	//string new_string = one_line.substr(first + 5, last - first - 1);
	//cout << new_string;
	//my_file.close();
#pragma endregion

	 
	string new_string = "";
	std::ifstream file("hello.nv");
	std::string line;
	
	while (std::getline(file, line))
	{
		new_string = print_to_console(line);
		cout << new_string;


		declere_integer(line);
	}
	file.close();





	/*Query query;
	query.type = UNDEFINED;
	ifstream myfile("file.txt");
	if (myfile.is_open())
	{
		string query_type;
		myfile >> query_type >> query.data;
		if (query_type == "Print")
		{
			cout << "text";
		}
		else if (query_type == "move")
		{
			query.type = MOVE;
		}
		myfile.close();)*/

}



