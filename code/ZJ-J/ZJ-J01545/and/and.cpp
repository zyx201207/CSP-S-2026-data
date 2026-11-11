#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans,n,m,a[200010];
bool vis[200010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=(1ll<<30);i>=1;i=(i>>1)){
    	int cnt=0;
    	for(int j=1;j<=n;j++){
    		if(vis[j]) continue;
    		if(a[j]&i) cnt++;
		}
		if(cnt>=m){
			ans+=i;
			for(int j=1;j<=n;j++){
				if(!(a[j]&i)) vis[j]=1;
			}
		}
	}
	cout<<ans;
    return 0;
}
