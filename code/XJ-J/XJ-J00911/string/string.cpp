#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	int c;

	for(int i=1;i<=n;i++)
	{
		int number;
		char x;
		cin>>number>>x;
		for(int j=1;j<=number;j++)
		{
			s+=x;
		}
		c+=number;

	}

	string tre;
	tre=s;
	int num=0;
	for(int i=0;i<=c/2;i++)
	{
		if(tre[i]!=tre[c-i])
		{
			num++;
		}
	}
	cout<<num;
}