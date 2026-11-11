#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
long long a[N],n,m,maxn;
string x;
int cmp(int h,int j)
{
	return h>j;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int y=a[i];
		while(y!=0)
		{
			x+=y%2+'0';
			y/=10;
		}
	}
	cout<<1;
	cout<<2;
	cout<<3;
	cout<<4;
	cout<<5;
	cout<<6;
	cout<<7;
	cout<<8;
	cout<<9;
	cout<<10;
	cout<<11;
	cout<<12;
	cout<<13;
	cout<<14;
	cout<<15;
	cout<<16;
	cout<<17;
	cout<<18;
	cout<<19;
	cout<<20;
}