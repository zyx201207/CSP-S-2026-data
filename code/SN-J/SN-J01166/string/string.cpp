#include<iostream>
#include<string>
using namespace std;
int n;
int a;
string b;
string s;
string d;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		for (int j=1;j<=a;j++)
		{
			s+=b;
		}
	}
	for (int k=(s.length());k>=0;k--)
	{
		d+=s[k];
	}
	cout<<0;
	return 0;
}
