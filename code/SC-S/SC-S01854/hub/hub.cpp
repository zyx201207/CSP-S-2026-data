#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,x,y,s,i,o,a[1000020],p;
vector<long long>v[1000020];
unordered_map<long long,long long>l,ll;
void b(long long root,long long fa)
{
	l[root]=1;
	for(auto _:v[root])
	{
		if(_!=fa)b(_,root);
	}
}
void bb(long long root,long long fa,long long mm)
{
	ll[root]=mm;
	for(auto g:v[root])
	{
		if(g==fa)continue;
		if(l[root]==1)bb(g,root,1);
		else bb(g,root,mm+1);
	}
}
void d(long long h,long long u)
{
	if(u==k)
	{
		l.clear();
		p=0;
		for(int j=1;j<=o;j++)
		{
			if(p>2)break;
			if(l[a[j]]==0)
			{
				p++;
				b(a[j],0);
			}
		}
		if(p<=2)
		{
			for(int j=1;j<=n;j++)ll[j]=INT_MAX;
			for(int j=1;j<=o;j++)
			{
				bb(a[j],0,0);
			}
			for(int j=1;j<=o;j++)ll[a[j]]=0;
			long long ma=INT_MIN;
			for(int j=1;j<=n;j++)
			{
				ma=max(ma,ll[j]);
			}
			s=min(s,ma);
		}
		return ;
	}
	for(int j=h+1;j<=n;j++)
	{
		a[++o]=j;
		d(j,u+1);
		o--;
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		s=INT_MAX;
		cin>>n>>k;
		for(i=1;i<n;i++)
		{
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		d(0,0);
		cout<<s<<endl;
	}
}
/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/