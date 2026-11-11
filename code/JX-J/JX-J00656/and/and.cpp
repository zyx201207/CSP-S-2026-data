#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000000],ans=0,vis[1000000];
void dfs(int x,int z){
	if(x>m){
		ans=max(z,ans);
		return;
	}
	if(x==1){
		for(int i=1;i<=n;i++){
			vis[i]=1;
			dfs(x+1,a[i]);
			vis[i]=0;
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(x+1,z&a[i]);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int mx=0,num;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) num=a[i];
		else num&=a[i];
	}
	if(n<=20){
		dfs(1,0);
		cout<<ans;
	}
	else{
		if(m==1) cout<<mx;
		else if(m==2){
			int mxx=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					mxx=max(mxx,a[i]&a[j]);
				}
			}
			cout<<mxx;
		}
		else if(m==n) cout<<num;
	}
	return 0;
}
