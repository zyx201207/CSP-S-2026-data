#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200010][40],vis[200010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		int cnt=0;
		while(x!=0){
			a[i][cnt]=x%2;
			x/=2;
			cnt++;
		}
	}
	int ans=0;
	for(int i=33;i>=0;i--){
		int sum=0;
		for(int j=1;j<=n;j++){
			if(vis[j]==0){
				sum+=a[j][i];
			}
		}
		if(sum>=m){
			for(int j=1;j<=n;j++){
				if(vis[j]==0&&a[j][i]==0){
					vis[j]=1;
				}
			}
			int p=1;
			for(int k=1;k<=i;k++){
				p*=2;
			} 
			ans+=p;
		}
	}
	cout<<ans;
	return 0;
}
/*
__builtin_popcount()
*/
