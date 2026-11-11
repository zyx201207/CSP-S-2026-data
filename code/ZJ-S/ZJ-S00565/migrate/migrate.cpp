#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	int x,step;
};
void solve()
{
	int n,d,cnt=0;
	int x[2000200],flag=0,minn=1e18;
	cin>>n>>d>>x[1];
	if(n==1)
	{
		cout<<0;
		return ;
	}
	vector<int> a[2000200];
	for(int i=2;i<=n;i++)
	{
		cin>>x[i];
		minn=min(minn,x[i]-x[i-1]);
	}
	if(minn<d)
	{
		cout<<0;
		return ;
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(x[i]+d>=x[j])
				a[i].push_back(j);
	queue<node> q;
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{
			q.push({x[i],0});
			while(q.size())
			{
				node t=q.front();
				q.pop();
				if(t.x==x[j])
				{
					if(!flag)
						flag=t.step;
					else 
					{
						if(t.step==flag)
							cnt++;
						break;
					}
				}
				for(int k=0;k<a[t.x].size();k++)
				{
					int v=a[t.x][k];
					q.push({v,t.step+1});
			    }
			}		
		}
	cout<<cnt;
	return ;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,c,t1;
	cin>>c>>t;
	t1=t;
	while(t--)
	{
		cout<<t1-t<<"\n";
	}
	return 0;
}