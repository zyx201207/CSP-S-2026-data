/*
Author:蝴蝶(lg uid 663638)
Start Coding: 15:41 (1~6)  16:04 (11,12) 16:15 (13,14)
Finish Coding: 15:58 (1~6) 16:05 (11,12) 16:18 (13,14)
Finish Debugging: 16:04 (1~6) 16:11 (11,12) 16:25(13,14) 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,ans,x[2000006],dis[302][302],num[302][302],r[2000006];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;ans=0;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(c<11||c>14)
		{
			for(int i=n;i;i--)for(int j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]<=d)dis[i][j]=num[i][j]=1;
				else{dis[i][j]=0x66ccffll;num[i][j]=0;}
				for(int k=i+1;k<j;k++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				for(int k=i+1;k<j;k++)if(dis[i][j]==dis[i][k]+dis[k][j])num[i][j]=min(0x66ccffll,num[i][j]+num[i][k]*num[k][j]);
				if(dis[i][j]!=1)num[i][j]/=dis[i][j]-1;
			}
			for(int i=1;i<=n;i++)for(int j=n;j>i;j--)if(num[i][j]==2)ans++;
			cout<<ans<<'\n';
		}
		if(c==11||c==12)cout<<(d<2*(x[2]-x[1])?0:max(n-2*d/(x[2]-x[1])+1,0ll))<<'\n';
		if(c==13||c==14)
		{
			for(int i=1,j=1;i<=n;i++)
			{
				while(j<=n&&x[j]<=x[i]+d)j++;
				r[i]=j-1;
			}
			for(int i=1;i<=n;i++)ans+=max(0ll,r[r[i]-1]-max(r[r[i]-2],r[i]));
			cout<<ans<<'\n';
		}
	}
}
//bug: 路径有重复计数&可能哪也去不了&有可能一步到 

/*
这道题让我想起了白鸟过河滩

小 B 在 CSP-J2021 T1 中没开 long long，100->60，警钟长鸣 
小 B 在 CSP-S2023 T4 中写了个假做法拿到了期望的分数，希望今年数据也这么水 
小 B 在 CSP-S2025 T2 中 int 函数没写返回值 100->0，警钟长鸣
小 B 在 NOIP2025 T1 中只测一头一尾大样例导致没发现写错了 100->75，警钟长鸣
小 B 在 SDOI2025 中犯了很多错误 
小 B 在 APIO2026 T2 中认为大于等于小于其实是两种情况，并且认定题目不可做，警钟长鸣 
*/
