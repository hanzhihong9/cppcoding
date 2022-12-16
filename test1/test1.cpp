// test1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void test1() {
	cout << "\n test1----------------" << endl;
	vector<int> nums{1,2,4,5,6};
	for_each(nums.begin(), nums.end(), [](int num) {
		cout << num << " ";
	});
}

void test2() {
	struct Point {
		int x;
		int y;
	};
	Point pt1{ 1, 2 };
	Point pt2{ 3, 4 };
	Point pt3{ 5, 6 };
	Point pt4{ 7, 8 };

	vector<Point> triangle1{ pt1, pt2, pt3 };
	vector<Point> triangle2{ pt2, pt3, pt1 };
	vector<Point> triangle3{ pt3, pt1, pt2 };
	vector<Point> triangle4{ pt1, pt2, pt4 };
	
	cout << "\n test2-1---------------" << endl;
	auto isPermutation1 = is_permutation(triangle1.begin(), triangle1.end(), triangle3.begin(),
		[](Point lhs, Point rhs) {
		cout << lhs.x << lhs.y << rhs.x << rhs.y << endl;
		return lhs.x == rhs.x && lhs.y == rhs.y;
	    }
		);
	if (isPermutation1) {
		cout << " isPermutation " << endl;
	}
	else {
		cout << " is not Permutation " << endl;
	}
	cout << "\n test2-2----------------" << endl;
	auto isPermutation2 = is_permutation(triangle1.begin(), triangle1.end(), triangle4.begin(),
		[](Point lhs, Point rhs) {
		cout << lhs.x << lhs.y << rhs.x << rhs.y << endl;
		return lhs.x == rhs.x && lhs.y == rhs.y;
	}
	);

	if (isPermutation2) {
		cout << " isPermutation " << endl;
	}
	else {
		cout << " is not Permutation " << endl;
	}

}

void test3() {
	cout << "\n test3---before-------------" << endl;
	vector<int> nums{ 1,2,4,5,6 };
	for_each(nums.begin(), nums.end(), [](int num) {
		cout << num << " ";
	});
	int bonus{ 5 };
	transform(nums.begin(), nums.end(), nums.begin(), [bonus](int num) {
		return num += bonus ;
	});
	cout << "\n test3---after-------------" << endl;
	for(auto n: nums){
		cout << n << " ";
	};
}

void test4() {
	cout << "\n test4---before-------------" << endl;
	vector<int> nums{ 1,2,3,4,5,6 };
	for_each(nums.begin(), nums.end(), [](int num) {
		cout << num << " ";
	});
	int bonus{ 5 };
	nums.erase(remove_if( nums.begin(), nums.end(), [](int num) {
		return num %2 == 0;
	}), nums.end());
	cout << "\n test4---after-------------" << endl;
	for (auto n : nums) {
		cout << n << " ";
	};
}

class Person {

	friend ostream& operator << (ostream & os, const Person& p);
private: 
	string name;
	int age;

public:
	Person(string name, int age) : name{ name }, age{ age } {}
	Person(const Person& p) : name{ p.name }, age{ p.age } {}
	~Person() = default;

	string getName() { return name; }
	int getAge() { return age; }
	void setName( const string& name) { this->name = name; }
	void setName(int age) { this->age = age; }


};

ostream& operator << (ostream& os, const Person& p)
{
	os << "[" << p.name << p.age << "]";
	return os;
}

void test5() {
	cout << "\n test5---before-------------" << endl;
	Person p2{ "Lucy", 20 };
	Person p1{ "Nancy", 10 };
	Person p3{ "Peter", 90 };

	vector<Person> persons{ p1, p2, p3};

	for (const auto& n : persons) {
		cout << n << " ";
	};

	sort(persons.begin(), persons.end(), [](Person lp, Person rp) {
		return lp.getName() > rp.getName();
	});
	cout << "\n test5---after-------------" << endl;
	for (const auto &n : persons) {
		cout << n << " ";
	};
}

bool inBetween(const vector<int>& nums, int start, int end) {
	bool ret{ false };
	ret = all_of(nums.begin(), nums.end(), [start, end](auto n) {
		return n >= start && n <= end;
	});
	return ret;
}

void test6() {
	cout << "\n test6---before-------------" << endl;
	cout << boolalpha;
	vector<int> nums(10);
	iota(nums.begin(), nums.end(), 1);
	for (auto n : nums) {
		cout << n << " ";
	}
	bool isin = inBetween(nums, 1, 4);
	cout << "is in  1, 4 -> "<< isin <<  endl;

	isin = inBetween(nums, 1, 90);
	cout << "is in  1,90 -> " << isin << endl;
	cout << "\n test6---before-------------" << endl;
}

class PassworValidator {
private:
	char restricted_symbol{ '$' };
	vector<char> restricted_symbols{'@', '#'};
	int foo1[3] = { 10, 20, 30 };
	int foo[3]{ 10, 20, 30 };
public:
	bool isValid(string password) {
		return all_of(password.begin(), password.end(), [this](char p) {
			// bool isValid = false; //  = p == restricted_symbol;
			//if (!isValid) {
				// isValid = 
				return none_of(restricted_symbols.begin(), restricted_symbols.end(), [p](char s) {
					return p == s;
				});
			// }
			// return isValid;
		});
	}
};
void test7() {
	PassworValidator validator;
	
	vector<string> passwords{ "ewrwr" , "#ewrwr" , "$ewrwr" };
	for (const auto& p : passwords) {
		string ret = validator.isValid(p) ? " is valid" : " is not valied";
		cout << p << ret << endl;
	}
	
}

int main()
{
    std::cout << "Hello World!\n"; 
	// test1();
	// test2();
	// test3();
	// test4();
	// test5();
	// test6();
	test7();
}

