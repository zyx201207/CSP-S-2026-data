#include<bits/stdc++.h>
using namespace std;
string a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int m;
		char b;
		cin>>m>>b;
		for(int i=0;i<m;i++)
		{
			a+=b;
		}
	}
	int l=a.length(),js=0;
	for(int i=0;i<l/2;i++)
	{
		string b=a;
		reverse(a.begin(),a.end());
		if(b==a)
		{
			break;
		}
		if(a[i]!=a[l-i-1])
		{
			a[i]=a[l-i-1];
			js++;
		}
	}
	cout<<js;
	return 0;
}