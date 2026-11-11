#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m;
ll ans,a[N];
bool vis[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	//LL!
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],vis[i]=1;
	for(int i=30;i>=0;i--){
		int gs=0;
		for(int j=1;j<=n;j++)
			if(vis[j]&&((a[j]>>i)&1)) gs++;
		if(gs>=m){
			for(int j=1;j<=n;j++)
				if(vis[j]){
					if(((a[j]>>i)&1)==0) vis[j]=0;
				}
			ans+=(1ll<<i);
		}
	}
	cout<<ans;
	return 0;
}
