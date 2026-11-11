#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N],n,m,ans;
bool vis[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)vis[i]=1;
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(vis[j]&&((a[j]>>i)&1)){
				cnt++;
			}
		}
		if(cnt>=m){
			ans=ans|(1<<i);
			for(int j=1;j<=n;j++){
				if(vis[j]&&!((a[j]>>i)&1)){
					vis[j]=0;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
