#include<bits/stdc++.h>
using namespace std;
int c,T;
long long n,d,a[2000005],ans,k;

struct node{
	int a,dep;
};

long long BFS(int x,int y)
{
	k=1e17;
	int cnt=0;
	queue<node> q;
	q.push({x,0});
	while(!q.empty())
	{
		node now=q.front();
		q.pop();
		if(now.dep>k||now.dep>y-x)
		{
			break;
		}
		if(now.a==y)
		{
			k=now.dep;
			cnt++;
			continue;
		}
		if(now.dep!=k)
		{
			for(int i=now.a+1;i<n;i++)
			{
				if(a[i]-a[now.a]<=d)
				{
					q.push({i,now.dep+1});
				}
				else
				{
					break;
				}
			}
			for(int i=now.a-1;i>=0;i--)
			{
				if(a[now.a]-a[i]<=d)
				{
					q.push({i,now.dep+1});
				}
				else
				{
					break;
				}
			}
		}
	}
	return cnt;
}

void solve()
{
	cin>>n>>d;
	ans=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(BFS(i,j)==2)
			{
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		solve();
	}
} 
