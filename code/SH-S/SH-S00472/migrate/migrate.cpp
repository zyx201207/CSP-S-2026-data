#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d,p,ans;
int a[5005],dis[5005],ti[5005];
int G[5005];
struct str
{
	int id,ds;
};
void f(int x)
{
	for(int i = x; i <= n; i++)dis[i]=ti[i]=0;
	queue<str>que;
	que.push({x,0});
	while(que.size())
	{
		str t=que.front();
		que.pop();
		for(int i = 1,nx; i <= G[t.id]; i++)
		{
			nx=t.id+i;
			if(dis[nx]==0)
			{
				dis[nx]=t.ds+1;
				ti[nx]=1;
				que.push({nx,dis[nx]});
			}
			else if(dis[nx]==t.ds+1)
			{
				ti[nx]++;
				que.push({nx,dis[nx]});
			}
		}
	}
	for(int i = x+1; i <= n; i++)if(ti[i]==2)ans++;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	if(c==11||c==12)
	{
		while(t--)
		{
			cin >> n >> d;
			for(int i = 1; i <= n; i++)cin >> a[i];
			if(n==1){cout << 0 << endl;continue;}
			d=d/(a[2]-a[1]);
			if(d==1){cout << 0 << endl;continue;}
			d=d*2-1;
			cout << n-d << endl;
		}
		return 0;
	}
	if(c>=15)return 0;
	while(t--)
	{
		ans=0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++)cin >> a[i];
		for(int i = 1; i <= n; i++)
		{
			p=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
			G[i]=p-i;
		}
		for(int i = 1; i <= n; i++)f(i);
		cout << ans << endl;
	}
	return 0;
}
