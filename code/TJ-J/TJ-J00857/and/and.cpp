#include <bits/stdc++.h> 
using namespace std;
int a,b,k,x1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	int x[a];
	int l[32];
	l[0]=2;
	for(int i=1;i<32;i++)
	{
		l[i]=l[i-1]*2;
	}
	for(int i=0;i<32;i++)
	{
		l[i]--;
	}
	for(int i=0;i<a;i++)
	{
		int x1;
		cin>>x1;
		x[i]=x1;
	}
	sort(x,x+a);
	k=x[a-1];
	for(int i=1;i<=b;i++)
	{
		k=k&x[a-i];
	}
	cout<<k;
	return 0;
}
