#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int A;
	string a;
	int B;
	string b;
	cin >> A;
	cin >> a;
	cin >> B;
	cin >> b;
	if(A == B)
	{
		cout << "1";
	}
	else
	{
		cout << "0000";
		return 0;
	}
	if('b' - 'a' <= 4 || 'a' - 'b' <= 4)
	{
		cout << "1";
	}
	else
	{
		cout << "000";
		return 0;
	}
	if('b' - 'a' <= 2 || 'a' - 'b' <= 2)
	{
		cout << "1";
	}
	else
	{
		cout << "00";
		return 0;
	}
	if(('a' + 1) == 'b' || ('b' + 1) == 'a')
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	return 0;
}
