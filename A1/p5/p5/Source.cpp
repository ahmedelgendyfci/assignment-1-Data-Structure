#include <iostream>
#include <string>
#include <set>
using namespace std;


void RecPermute(set<string>& perms, string soFar, string rest) {
	if (rest == "")
		perms.insert(soFar);
	else
	for (unsigned int i = 0; i < rest.length(); i++) {
		string next = soFar + rest[i];
		string remaining = rest.substr(0, i) + rest.substr(i + 1);
		RecPermute(perms, next, remaining);
	}
}

void ListPermutations(string s) {
	set<string> perms;
	RecPermute(perms, "", s);
	for (set<string>::iterator it = perms.begin(); it != perms.end(); it++) {
		cout << *it << endl;
	}
}

int main() {
	ListPermutations("Mkkaa");
	system("pause");
	return 0;
}
