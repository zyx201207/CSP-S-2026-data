#include<bits/stdc++.h>
using namespace std;
int main()
{
	string c1,s1,c2,s2;
	string a[100],b[100];
	cin >> c1 >> s1 >> c2 >> s2;
	for(int i = 0;i <= 2;i++)
	{
		a[i] = s1;
		b[i] = s2;
	}
	if(c1 == c2)
	{
		cout << "1";
	}else
	{
		cout << "0000";
		return 0;
	}
	if(a[1] != b[1])
	{
		cout << "1";
	}else{
		cout << "000";
		return 0;
	}
	if((a[2] == "A" or "B" or "C" && (b[2] == "A" or "B" or "C")))
	{
		cout << "00";
		return 0;
	}else{
		cout << "1";
	}
	if((a[2] + 'a' == b[2]) && (a[2] != "C" or b[2] != "C" or a[2] != "A" or b[2] != "A")) 
	{
		cout << "1";
	}else{
		cout << "0";
	}
	return 0;
}
