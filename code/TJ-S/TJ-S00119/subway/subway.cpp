#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct stop{
	int w=0;
	int connect[21]={0};
	int cnt=0;
};
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	stop s[m+1];
	int l[n+1][m+1]={0};
	for(int i=1;i<=m;i++)
	{
		cin>>s[i].w;
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			l[i][a]=t;
			s[a].connect[s[a].cnt+1]=i;
			s[a].cnt++;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int xr,yr,tmin=1e9;
		cin>>xr,yr;
		for(int i=1;i<=s[xr].cnt;i++)
		{
			if(l[i][yr]!=0&&l[i][yr]+l[i][xr]<tmin)
			{
				tmin=l[i][yr]+l[i][xr];
			}
			if(l[i][yr]==0)
			{
			    for(int j=1;j<=m;j++)
			    {
				    int t2=0;
				     if(l[i][j]!=0)
				    {
					    t2+=1;
				    }
			    }
			}
		}
		cout<<s[xr].w+s[yr].w+tmin;
	}
	return 0;
 } 
