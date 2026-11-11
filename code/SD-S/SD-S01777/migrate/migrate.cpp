#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e6+10;
int c,t,n,m,x[MAXN],cnt,now,tot,ans,ls;
void dfs(int from,int to,int step)
{
	if(step>tot||cnt>2) return;
	if(from==to)
	{
		if(step==tot) cnt++;
		return;
	}
	for(int i=1;;i++)
	{
		if(x[from+i]-x[from]<=m&&from+i<=to) dfs(from+i,to,step+1);
		else break;
	}
		
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		ans=0;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+3;j<=n;j++)
			{
				cnt=0;
				now=i+1;
				tot=0;
				ls=i;
				while(now<j)
				{	
					if(x[now+1]-x[now]>m) break;
					while(x[now]-x[ls]<=m)
					{
						if(now==j) break;
						now++;
					}
					if(x[now]-x[ls]>m&&now-ls>1) now--;
					tot++;
					ls=now-1;				
				}
				dfs(i,j,0);
				if(cnt==2) ans++;  		
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
 } 
 /*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

 
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

 */
