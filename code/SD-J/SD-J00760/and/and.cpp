#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int a[N],n,m;
bool vis[N];
int maxx;
void dfs(int res,int dist){
	if(dist==m){
		maxx=max(res,maxx);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			if(dist==0){
				dfs(a[i],dist+1);
			}else{
				dfs(res&a[i],dist+1);
			}
			vis[i]=false;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}else if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=max(a[i],ans);
		}
		cout<<ans;
	}else if(m==2&&n<=25000){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}else if(n<=20){
		dfs(0,0);
		cout<<maxx;
	}else{
		cout<<0;
	}
	return 0;
}
