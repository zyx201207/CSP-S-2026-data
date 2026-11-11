/*
Author:蝴蝶(lg uid 663638)
Start Coding: 16:35 (1~3)  17:42 (13,14)
Finish Coding: 16:50 (1~3)  17:42 (13,14)
Finish Debugging: 16:52 (1~3) 17:44 (13,14)
*/
#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,Ans,m,vis[1000006],res[1000006];
vector<int>g[1000006];
void dfs1(int u,int fa)
{
	if(!res[u])return;vis[u]=1;
	for(int v:g[u])if(v!=fa)dfs1(v,u);
}
int dfs2(int u,int fa)
{
	if(res[u])return 0;int ans=0x66ccff;
	for(int v:g[u])if(v!=fa)ans=min(ans,dfs2(v,u))+1;
	return ans;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;Ans=0x66ccff;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1,u,v;i<n;i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(c==13||c==14)
		{
			m=n/2;
			if(k>2*m)cout<<"0\n";
			else if(k>m)cout<<"1\n";
			else cout<<(m-k-1)/4+2<<'\n';
			continue; 
		}
		for(int i=0,cnt,ans;i<(1<<n);i++)
		{
			for(int j=1;j<=n;j++)vis[j]=res[j]=0;cnt=0;
			for(int j=0;j<n;j++)if(i&(1<<j)){cnt++;res[j+1]=1;}
			if(cnt!=k)continue;cnt=0;
			for(int j=1;j<=n;j++)if(!vis[j]&&res[j]){cnt++;dfs1(j,0);}
			if(cnt>2)continue;ans=0;
			for(int j=1;j<=n;j++)if(!res[j])ans=max(ans,dfs2(j,0));
			Ans=min(ans,Ans);
		}
		cout<<Ans<<'\n';
	}
}
/*
退役选手前来复健
近半年的停训对我的码速产生了很大的影响，好在思维可能没有过度退化，应该不会比去年的自己弱很多
小蝴蝶还有很多话想说，都留到 NOIP 吧（尽管好像不一定能去的样子），届时我也满 14 岁了 
估分的话可能是 100+100+40+25=265
另外洛天依可爱
另外禾念啥时候再办全员演唱会 
*/
