#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000003],minn,cnt,ans;
bool vis[2000003];
void dfs(int id,int e,int tmp){
	if(vis[id]) return;
	vis[id]=1;
	if(id==e){
		minn=min(tmp,minn);
		return;
	}
	for(int i=1;i<=n;i++){
		if(i==id) continue;
		if(abs(x[i]-x[id])>d) continue;
		dfs(i,e,tmp+1);
	}
	return;
}
void dfs2(int id,int e,int tmp,int g){
	if(vis[id]) return;
	vis[id]=1;
	if(tmp>g) return;
	if(id==e&&tmp==g){
		cnt++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(i==id) continue;
		if(abs(x[i]-x[id])>d) continue;
		dfs2(i,e,tmp+1,g);
	}
	return;
}
int main(){
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				minn=INT_MAX,cnt=0;
				memset(vis,0,sizeof vis);
				dfs(i,j,0);
				memset(vis,0,sizeof vis);
				dfs2(i,j,0,minn);
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
