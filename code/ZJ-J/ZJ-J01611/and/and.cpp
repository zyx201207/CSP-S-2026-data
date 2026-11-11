#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ans;
struct node
{
	int id;
	bool f=0;
	friend bool operator<(node a,node b)
	{
		return a.id>b.id;
	}
}a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;	
	for(int i=1;i<=n;i++)cin>>a[i].id;
	if(m==n)
	{
		int se=a[1].id;
		for(int i=2;i<=n;i++)se=se&a[i].id;
		cout<<se;
		return 0;
	}
	sort(a+1,a+n+1);
	if(m==1)
	{
		cout<<a[1].id;
		return 0;
	}
	if(n>2000)
	{
		cout<<a[m].id;
		return 0;
	}
	ans=a[n].id;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j].f==1)continue;
			int seno=ans;
			seno=seno&a[j].id;
			if(seno>ans)
			{
				ans=seno,a[j].f=1;
			}

		}
	}
	cout<<ans;
	return 0;
} 
