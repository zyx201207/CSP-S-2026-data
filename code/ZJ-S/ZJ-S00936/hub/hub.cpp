#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,ans,n,k,x,y,a[200010];
int dis[4010][4010];
int vis[4010];
int cnt[4010];
int ck(int x){
	int tmp=LLONG_MAX;
	for(int i=1;i<=n;i++){
		if(vis[i])tmp=min(tmp,dis[i][x]);
	}
	return tmp;
}
void dfs(int x,int st){
	if(st==k){
		int tmp=0;
		memset(cnt,0,sizeof cnt);
		int q=0,len=k;
		for(int i=1;i<=n;i++){
			if(vis[i])cnt[++q]=i;
		}
		for(int i=1;i<q;i++){
			for(int j=i+1;j<=q;j++){
				if(dis[cnt[i]][cnt[j]]==1)len--;
			}
		}
		if(len>2)return;
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
			tmp=max(tmp,ck(i));
		}
		ans=min(ans,tmp);
		return;
	}
	if(x>n)return;
	vis[x]=1;
	dfs(x+1,st+1);
	vis[x]=0;
	dfs(x+1,st);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		memset(vis,0,sizeof vis);
		ans=LLONG_MAX;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=200000;
			}
		}
		for(int i=1;i<n;i++){
			cin>>x>>y;
			dis[x][y]=dis[y][x]=1;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				if(dis[i][k]==200000)continue;
				for(int j=1;j<=n;j++){
					if(dis[k][j]==200000)continue;
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		dfs(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}
