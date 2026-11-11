#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],n,m;
bool vis[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],vis[i]=1;
	for(int i=30;i>=0;i--){
		int num=0;
		for(int j=1;j<=n;j++){
			if(!vis[j]) continue;
			if(a[j]&(1<<i)) num++;
		}
		if(num>=m){
			for(int j=1;j<=n;j++){
				if(!(a[j]&(1<<i))) vis[j]=0;
			}
		}
	}
	int ans=(1<<31)-1;
	for(int i=1;i<=n;i++){
		if(vis[i]) ans&=a[i];
	}
	cout<<ans;
	return 0;
}
