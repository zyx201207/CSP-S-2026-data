#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,m,i,j,pd[100][100],x,y,dis[100][100],ans,f[100],fa[100];
void dfs(int x,int xch){
	int i;
	for(i=1;i<=n;i++)
		if(pd[x][i])
			if(dis[xch][x]+1<dis[xch][i]){
				dis[xch][i]=dis[xch][x]+1;
				dfs(i,xch);
			}
}
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void dg(int t,int sum){
	int ss,s,i,j,mi,fx,fy;
	if(t==n+1){
		if(sum==m){
			ss=0;s=0;
			for(i=1;i<=n;i++)fa[i]=i;
			for(i=1;i<=n;i++)
				for(j=i+1;j<=n;j++)
					if(f[i]&&f[j]&&pd[i][j]){
						fx=find(i);fy=find(j);
						if(fx!=fy)fa[fx]=fy;
					}
			for(i=1;i<=n;i++)
				if(f[i]&&fa[i]==i)ss++;
			if(ss<=2){
				for(i=1;i<=n;i++){
					mi=1e9;
					for(j=1;j<=n;j++)
						if(f[j])
							mi=min(mi,dis[i][j]);
					s=max(s,mi);
				}
				ans=min(ans,s);
			}
		}
		return ;
	}
	f[t]=1;
	dg(t+1,sum+1);
	f[t]=0;
	dg(t+1,sum);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				pd[i][j]=0,dis[i][j]=1e9;
		for(i=1;i<n;i++){
			cin>>x>>y;
			pd[x][y]=pd[y][x]=1;
		}
		for(i=1;i<=n;i++)dis[i][i]=0,dfs(i,i);
		ans=1e9;
		dg(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
/*
100+100+40+15=255
wang zhe rong yao jia qiang chang e & shen meng xi
wang zhe id : xyymyj
*/
