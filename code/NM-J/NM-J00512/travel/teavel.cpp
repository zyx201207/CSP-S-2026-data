#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b;
	string c,d;
	cin >> a >> c >> b >> d;
	
//	cout << "000";
//	cout << d[2]+1;
//	return 0;
	
	if(a==b)
		cout << 1;
	else
	{
		cout << "0000";
		return 0;
	}
		
	if(c[0]==d[0])
		if(c[1] == d[1])
			cout << 1;
	else
	{
		cout <<"000";
		return 0;
	}
	if(c[2] == 'D' && d[2] == 'C'){
		cout << "00";
		return 0;
	}
	if(c[2]=='C' && d[2] == 'D'){
		cout << "00";
		return 0;
	}
	else 
		cout << "1";
		
	if(c[2] == d[2]+1 || c[2]+1==d[2])
		cout << 1;
	else
		cout << "0";
	
	return 0;
}
