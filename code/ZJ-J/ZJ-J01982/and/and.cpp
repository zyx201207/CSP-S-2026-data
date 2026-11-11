#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],t[50][N],vis[N],cnt[50],ans,sum;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	ans=(1<<30)-1;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		for(int j=31;j>=0;--j){
			t[j][i]=(a[i]>>j)%2;
			if((a[i]>>j)%2==1) cnt[j]++;
		}
	}
	for(int j=31;j>=0;--j){
		if(cnt[j]>=m){
			for(int i=1;i<=n;++i){
				if(t[j][i]==0){
					if(vis[i]==0){
						sum--;
						for(int u=31;u>=0;--u) if((a[i]>>u)%2==1) cnt[u]--;
					}
					vis[i]=1;
				}
			}
		}
	}
	for(int i=1;i<=n;++i) if(vis[i]==0) ans&=a[i];
	cout<<ans;
}
