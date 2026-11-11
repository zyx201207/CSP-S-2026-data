#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d;
int x[2000050];
int vis[2000050];
//int a[2000050];
int cnt[2000050];
void dfs(int now){
	if(now>n){
		return ;
	}
	for(int i=now+1;i<=n;i++){
		if(x[i]-x[now]>d) break;
		if(vis[i]>vis[now]+1){
			vis[i]=vis[now]+1;
			cnt[i]=1;
		}
		else if(vis[i]==vis[now]+1){
			cnt[i]++;
		}
		dfs(i);
	}
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;	
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int cha=x[2]-x[1],f=0;
		for(int i=3;i<=n;i++){
			if(x[i]-x[i-1]!=cha){
				f=1;break;
			}
		}
		if(f==0 && n>9){
			if(d>=2*cha && d<3*cha) cout<<n-3<<"\n";
			else cout<<"0\n";
			continue;
		}
		int ans=0;
		for(int i=1;i<=n-3;i++){
			memset(vis,0x3f3f,sizeof vis);
			memset(cnt,0,sizeof cnt);
			vis[i]=0;
			dfs(i);
			for(int j=i+3;j<=n;j++){
			//	cout<<cnt[j]<<" "<<vis[j]<<"\n";
				if(cnt[j]==2) ans++;
			}
		//	cout<<"\n";
		}
		cout<<ans<<"\n";
	}
	return 0;
}