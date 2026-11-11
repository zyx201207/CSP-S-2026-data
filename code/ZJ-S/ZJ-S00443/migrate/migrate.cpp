#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,ans,a[2000005];
vector<int> tr[10005];
int cny[10005];
int stp[10005];
queue<int> sp;
queue<int> p;
void bfs(int s)
{
	memset(stp,0x3f,sizeof stp);
	memset(cny,0,sizeof cny);
	p.push(s);
	stp[s] = 0;
	cny[s] = 1;
	while(p.size())
	{
		int tp = p.front();
		p.pop();
		for(int i : tr[tp])
		{
			if(stp[tp]+1 < stp[i])
			{
				stp[i] = stp[tp]+1;
				p.push(i);
			}
			if(stp[tp]+1 == stp[i])
			{
				if(cny[i]==2)
					ans--;
				cny[i]+=cny[tp];
				if(cny[i]==2)
					ans++;
			}
		}
	}
}
signed main()
{
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c<=10)
	{
		while(t--)
		{
			cin>>n>>d;
			for(int i = 1;i <= n;i++)
			{
				cin>>a[i];
			}
			for(int i = 1;i <= n;i++)
			{
				for(int j = i-1;j > 0;j--)
				{
					if(a[i]-a[j] <= d)
					{
						tr[j].push_back(i);
					}
					else
						break;
				}
			}
			ans = 0;
			for(int i = 1;i <= n;i++)
			{
				bfs(i);	
			}
			for(int i = 1;i <= n;i++)
			{
				tr[i].clear();
			}
			cout<<ans<<'\n';
		}
	}
	else
	{
		while(t--)
		{
			cin>>n>>d;
			for(int i = 1;i <= n;i++)
			{
				cin>>a[i];
			}
			int x = a[2]-a[1];
			if(d/x<=1)
			{
				cout<<"0\n";
			}
			else
			{
				int len = d/x;
				cout<<max(n-len+1,0ll)<<'\n';
			}
		}
	}
	return 0;
}

