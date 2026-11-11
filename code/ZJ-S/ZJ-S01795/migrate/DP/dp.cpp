#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	for(int cs = 1 ; ; cs++)
	{
		cout << "Case #" << cs << ": ";
		system("./gen");
		system("./std");
		system("./test");
		if(system("diff -w std.out test.out"))
		{
			cout << "Wrong Answer!\n";
			return 0;
		}
		else cout << "Accepted!\n";
	}
	return 0;
}