#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//int a, c;
	string a , b , c ,d;
	cin >> a >> b >> c >> d;
	
	string s1 , s2 ,z1 , z2;
	
	if(a != c)
	{
		cout << "0000";
		return 0;
	}
	else
	{
		cout << "1";
		for(int i = 0;i <= 1;i++)
	{
		s1 += b[i];
		}
	//cout << s1;
	for(int i = 0;i <= 1;i++)
	{
		s2 += d[i];
	}
	//cout << s2;
	}
	if(s1 == s2)
	{
		cout << "1";
	}
	
	
	
	
	
	for(int i = 2;i <= 2;i++)
	{
		z1 = b[2];
	}
	//cout << z1;
	
	
	for(int i = 2;i <= 2;i++)
	{
		z2 = d[2];
	}
	//cout << z2;
	if(z1 ==  "E" && z2 == "F")
	{
		cout << "11";
	}
	fclose(stdin);
	fclose(stdout);
	//cout << a << " " << b  << " "<< c  << " "<< d;
	return 0;
}
