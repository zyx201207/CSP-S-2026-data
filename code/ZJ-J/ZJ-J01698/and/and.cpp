#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200010],p[50],s;
vector<int>q;
struct yu
{
	int t,a[200010];
}b[40];
void count(int x,int id)
{
	for(int i=30;i>=0;i--)
	{
		if(x>=p[i])
		{
			b[i].a[++b[i].t]=id;
			x-=p[i];
		}
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	p[0]=1;
	for(int i=1;i<=30;i++)p[i]=p[i-1]*2;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		count(a[i],i);
	}
	bool f=1;
	for(int i=30;i>=0;i--)
	{
		if(b[i].t>=m&&f)
		{
			f=0;s+=p[i];
			for(int j=1;j<=b[i].t;j++)q.push_back(b[i].a[j]);
			memset(b,0,sizeof b);
			for(int v:q)count(a[v],v);
		}
		else if(b[i].t>=m)
		{
			s+=p[i];
			q.clear();
			for(int j=1;j<=b[i].t;j++)q.push_back(b[i].a[j]);
			memset(b,0,sizeof b);
			for(int v:q)count(a[v],v);
		}
	}
	cout<<s;
	return 0;
}

