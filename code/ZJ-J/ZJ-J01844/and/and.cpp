#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200001],mx,ans;
bool vis[200001],w[200001][32];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i],ws=0;
		while(x){
			w[i][++ws]=x%2;
			x/=2;
		}
		mx=max(mx,ws);
	}
	for(int i=mx;i;i--){
		int sum=0;
		for(int j=1;j<=n;j++){
			if(vis[j]) continue;
			sum+=w[j][i];
		}
		if(sum<m) continue;
		for(int j=1;j<=n;j++){
			if(vis[j]) continue;
			if(w[j][i]==0) vis[j]=1;
		}
		ans+=(1ll<<(i-1));
	}
	cout<<ans;
}