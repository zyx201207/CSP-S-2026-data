#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],fj[200005][32],vis[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int xx=a[i];
		for(int j=30;j>=0;j--){
			if(xx>=(1<<j)){
				xx-=(1<<j);
				fj[i][j]=1;
			}
		}
		vis[i]=1;
	}
	int ans=0;
	for(int j=30;j>=0;j--){
		int num=0;
		for(int i=1;i<=n;i++){
			if(vis[i]) num+=fj[i][j];
		}
		if(num>=m){
			ans+=(1<<j);
			for(int i=1;i<=n;i++){
				if(!fj[i][j]) vis[i]=0;
			}
		}
	}
	cout<<ans;
}
