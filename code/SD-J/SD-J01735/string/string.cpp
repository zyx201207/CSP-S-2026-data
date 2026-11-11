#include<bits/stdc++.h>
using namespace std;
struct str
{
	int b;
	char c;
}a[26666];
int d;
string s;
long long l,r;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m=0,ai,ci;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].b>>a[i].c;
		l+=a[i].b;
	}
	l=(l+1)/2;
	d=1,r=n;
	while(1<r)
	{
		for(int i=1;i<=n;i++)
		{
			
		}
	}
	cout<<l;
	return 0; 
}
