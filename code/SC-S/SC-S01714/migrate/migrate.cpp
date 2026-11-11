#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d;
int a[303];
map<int,int> m[303][303];
int minnn[303][303];
int tot;
void dfs(int st,int now,int sp)
{
	if(sp>minnn[st][now]) return;
	m[st][now][sp]++;
	minnn[st][now]=min(minnn[st][now],sp);
	int i=1;
	while((a[i+now]-a[now])<=d && (i+now)<=n) i++;
	i--;
	while(i>0)
	{
//		cout<<st<<' '<<now+i<<' '<<sp+1<<endl;
		dfs(st,now+i,sp+1);
		i--;
	}
}
void query(int st)
{
	for(int i=1;i<=n;i++)
	{
		if(m[st][i][minnn[st][i]]==2) tot++;
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		tot=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				minnn[i][j]=9999999999;
				m[i][j].clear();
			}
		}
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			dfs(i,i,0);
			query(i);
		}
		cout<<tot<<endl;
		
	}
	return 0;
}