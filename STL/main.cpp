#include<iostream>
#include<array>
#include<vector>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"
#define delimeter "------------------------------------------------------------------------------ \n"


template <typename T>void vector_properties(const std::vector<T>& vec);


//#define STL_ARRAY
#define STL_VECTOR

void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_ARRAY
	//array-контейнер который хранит данные в виде статического массива
	const int N = 5;
	std::array<int, N> arr = { 3,5,8,13,21 };
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
#endif // STL_ARRAY
#ifdef STL_VECTOR
	//VECTOR-контейнер который хранит данные в виде динамического массива
	std::vector<int> vec = {0,1,1,2, 3,5,8,13,21,31 };
	
	try
	{
		for (int i = 0; i < vec.size() * 2; i++)
		{
			//cout << vec[i] << tab;
			cout << vec.at(i) << tab;
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	vector_properties(vec);
	vec.push_back(55);
	cout << delimeter<<endl;
	//vec.resize(18);
	vec.reserve(120);
	vec.shrink_to_fit();
	vec.insert(vec.begin()+8, vec.begin() + 3, vec.begin() + 7);//вставка элементов, в томчисле других массивов
	vec.insert(vec.begin() + 5, { 1024,2048,3072,4096 });
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec.at(i) << tab;
	}
	cout << endl;
	vector_properties(vec);
	cout << delimeter;
	/*std::vector<int> vec2(100);
	vector_properties(vec2);
	vec2.push_back(1024);
	vector_properties(vec2);
	cout << delimeter;*/

	/*std::vector<double> d_vec = { 2.7,3.14,8.3 };
	vector_properties(d_vec);
	cout << d_vec.back() << endl;
	cout << d_vec.front() << endl;*/
	int index;
	int count;
	int value;
	cout << "Введите индекс добавляемого значения: "; cin >> index;
	cout << "Введите колличество добавляемых значений: "; cin >> count;
	cout << "Введите добавляемое значения: "; cin >> value;
	cout << endl;
	//std::vector<int>::iterator it;
	//it = vec.begin()+index;
	//vec.insert(it, value);
	////vec.insert(it,index, value);

	vec.insert(vec.begin() + index,/*count,*/ value);
	for(std::vector<int>::iterator it = vec.begin();it<vec.end();++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	for (std::vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
	{
		cout << *it << tab;
	}
	for (int i : vec)cout << i << tab; cout << endl;
	

#endif // STL_VECTOR



}

template <typename T>void vector_properties(const std::vector<T>& vec)
{
	cout << "Size:     " << vec.size() << endl;
	cout << "MaxSize:  " << vec.max_size() << endl;
	cout << "Capasity: " << vec.capacity() << endl;
}