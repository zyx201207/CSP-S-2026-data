#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
    if( c1==c2)
    {
    	cout << "1";
    }
    else {
        cout << "0000";
        return 0;
    }
    int a=(s1[0]-'0')*10+(s1[1]-'0');	
    int b=(s2[0]-'0')*10+(s2[1]-'0');
    if (a==b)
    {
    	cout << "1";
    }else
    {
    	cout << "000";
    	return 0;
    }
    if (s1[2]<='C' && s1[2]>='A' && s2[2]<='C' && s2[2]>='A')
    {
    	cout << "1";
    }
    else if (s1[2]>'C' && s1[2]<='F' && s2[2]>'C' && s2[2]<='F')
    {
    	cout << "1";
	}
	else
	{
		cout << "00";
		return 0;
	}
	int x=s1[2]-'A';
	int y=s2[2]-'A';
	if (x-y==1 || x-y==-1)
	{
		cout << "1";
		return 0;
	}
	else
	{
		cout << "0";
	}
 }
