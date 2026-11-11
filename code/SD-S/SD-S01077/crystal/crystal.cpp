#include <bits/stdc++.h>
using namespace std;
const int N=500010,M=1e9;
int n,m;
struct st{
	int x,y;
}a[N];
bool cmp(st x,st y)
{
	return x.y<y.y;
}
int b,d,c;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x;
		b+=a[i].x;
	}
	d=abs(n*a[1].x-b);
	for(int i=1;i<=n;i++)
	{
		if(d>abs(n*a[i].x-b))
		{
		    d=abs(n*a[i].x-b);
			c=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		a[i].y=abs(a[c].x-a[i].x);
	}
	sort(a+1,a+n+1,cmp);
	int res=1;
	for(int i=2;i<=n;i++)
	{
		if(abs(a[1].x-a[i].x)<=m)
		{
			m=m-abs(a[1].x-a[i].x);
			res++;
		}
	}
	cout<<res;
	return 0;
}
