#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10,M=2e5+10;
int n,m,a[N],ans[N],cnt[N],vis[N][2],dis[N];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		memset(dis,0,sizeof(dis));
		for(int j=i;j<=n;j++){
			if(cnt[a[j]]>1){
				if(!vis[a[j]][0])vis[a[j]][0]=j;
				vis[a[j]][1]=max(vis[a[j]][1],j);
			}
		}
		for(int j=1;j<=m;j++){
			if(!vis[j][0])continue;
			for(int k=vis[j][0]+1;k<=vis[j][1];k++)dis[k]=-1;
		}
		int kt=n+1,jw=0;
		for(int j=1;j<=m;j++){
			if(!vis[j][0])continue;
			kt=min(kt,vis[j][0]);
			jw=max(jw,vis[j][1]);
		}
		if(a[kt]!=a[jw])
			dis[jw]=0;
		for(int j=i;j<=n;j++){
			if(dis[j]==0)ans[a[j]]++;
		}
		cnt[a[i]]--;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
} 
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int te=1;
//	cin>>te;
	while(te--){
		solve();
	}
	return 0;
}
