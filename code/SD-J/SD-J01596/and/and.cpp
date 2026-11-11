#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll a[N],ans;
int vis[N],n,m;
void dfs(int now,int h){
	if(now==n+1&&h==m){
		int f;
		ll cnt;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				cnt=a[i];
				f=i;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(vis[i]&&i!=f){
				cnt&=a[i];
			}
		}
		ans=max(ans,cnt);
		return;
	}
	if(h>m||(now==n+1&&h<m)){
		return;
	}
	vis[now]=1;
	dfs(now+1,h+1);
	vis[now]=0;
	dfs(now+1,h);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		ans=-1;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}else if(m==2){
		ans=-1;
		for(int i=1;i<=n;i++){
			ll cnt=a[i];
			for(int j=1;j<=n&&j!=i;j++){
				cnt&=a[j];
				ans=max(ans,cnt);
				cnt=a[i];
			}
		}
		cout<<ans;
	}else{
		dfs(1,0);
		cout<<ans;
	}
	return 0;
} 
