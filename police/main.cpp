#include<iostream>
#include<map>
#include<string>
#include<list>
#include<fstream>

#define tab "---"

using std::cin;
using std::cout;
using std::endl;

const std::map<int, std::string>CRIMES =
{
	{0, "N/A"},
	{1, "������ �� �������"},
	{2, "���������� ��������"},
	{3, "�������� � ������������ �����"},
	{4, "����������� ��������"},
	{5, "���� � ��������� ���������"},
	{6, "����������� �������"},
	{7, "������ ������������"},
};

class Crime
{
	int id; //������
	std::string place; //����� ��������������
public:
	int get_id()const
	{
		return id;
	}
	const std::string& get_place()const
	{
		return place;
	}
	void set_id(int id)
	{
		if (id > CRIMES.size())id = 0;
		this->id = id;
	}
	void set_place(const std::string& place)
	{
		this->place = place;
	}
	Crime(int id, const std::string& place)
	{
		set_id(id);
		set_place(place);
	}
	~Crime(){}
};
std::ostream& operator<<(std::ostream& os, const Crime& obj)
{
	return os << CRIMES.at(obj.get_id()) << "\t" << obj.get_place();
}
std::ofstream& operator<<(std::ofstream& ofs, const Crime& obj)
{
	ofs << obj.get_id() << " " << obj.get_place();
	return ofs;
}
void print(const std::map<std::string, std::list<Crime>>& base);
void save(const std::map<std::string, std::list<Crime>>& base, const std::string& filename);
std::map<std::string,std::list<Crime>> load(const std::string& filename);


void main()
{
	setlocale(LC_ALL, "");
	
	/*std::map<std::string, std::list<Crime>> base =
	{
		{"m777ab",{Crime(1,"��. ������"), Crime(2,"��.������"),Crime(4,"��.��������� �������")}},
		{"k231cc",{Crime(5,"��. ����� ������"), Crime(6,"��. ����� ������")}},
		{"p441oc",{Crime(3,"��. ������������"), Crime(7,"��. ������������")}}
	};
	print(base);
	save(base, "base.txt");*/
	std::map<std::string, std::list<Crime>> base = load("base.txt");
	print(base);
}

void print(const std::map<std::string, std::list<Crime>>& base)
{
	for (std::map<std::string, std::list<Crime>>::const_iterator it = base.cbegin(); it != base.cend(); ++it)
	{
		cout << it->first << ":\n";
		for (std::list<Crime>::const_iterator l_it = it->second.cbegin(); l_it != it->second.cend(); ++l_it)
		{
			cout << tab << *l_it << endl;
		}
		cout << endl;

	}

	//Range based for
	/*for (std::pair<std::string, std::list<Crime>>i : base)
	{
		cout << i.first << ":\n";
		for (Crime j : i.second)cout <<tab<< j << endl;
		cout << endl;
	}*/
}
void save(const std::map<std::string, std::list<Crime>>& base, const std::string& filename)
{
	std::ofstream fout(filename);
	//range based for
	for (std::pair<std::string, std::list<Crime>>i : base)
	{
		fout << i.first << ":\t";
		for (Crime j : i.second)fout /*<< tab*/ << j <<","/* endl*/;
		fout.seekp(-2,std::ios::cur);//������� ������ �� ������� �����
		fout << ";\n";
	}
	fout.close();
	std::string command = "notepad";
	command += filename;
	system(command.c_str());
}
std::map<std::string, std::list<Crime>> load(const std::string& filename)
{
	std::map<std::string, std::list<Crime>> base;
	std::string licence_plate;
	std::string all_crimes;

	std::ifstream fin(filename);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			std::getline(fin, licence_plate, ':');
			if (licence_plate.empty())continue;
			fin.ignore();
			std::getline(fin, all_crimes);
			size_t start=0;
			size_t end=0;
			
			while (end != std::string::npos)
			{
				end = all_crimes.find(',');
				std::string s_crime = all_crimes.substr(0, end);
				if (s_crime.empty())break;
				int id = std::stoi(s_crime, nullptr, 10);
				s_crime.erase(0, s_crime.find_first_of(' ') + 1);
				base[licence_plate].push_back(Crime(id, s_crime));
				all_crimes.erase(0, end + 1);
			}
		}
		fin.close();
	}
	return base;
}




