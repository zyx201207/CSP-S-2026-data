#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long q,a[100005];
	string z[100005],s;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>a[i]>>z[i];
		int x=a[i];
		string e=z[i];
		for(int p=1;p<=x;p++)
		{
			s+=e; 
		}
	}
	long long c=0;
	long long d;
	d=s.size();
	for(int i=0;i<d;i++)
	{
		if(s[i]!=s[d])
		{
			c++;	
		}
		d--;	
	}
	cout<<c;
	return 0;
}
