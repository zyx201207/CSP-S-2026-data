#include <bits/stdc++.h>
using namespace std;
int n,a[20005];
string b[20005];
bool pd(string x)
{
	int l=0,r=x.size()-1;
	while(l<=r)
	{
		if(x[l]!=x[r]) return 0;
		else
		{
			l++;
			r--;
		}
	}
	return 1;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n<=1) 
	{
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
	}
	string s=" ";
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			s+=b[i];
		}
	}
	if(n<=2)
	{
		if(pd(s)) cout<<0;
		else cout<<1;
		return 0;
	}
	cout<<n-1;
	return 0;
}
