#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],cnt,vis[200005],ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=31;k>=0;k--){
		cnt=0;
		for(int i=1;i<=n;i++) if(a[i]&(1<<k)&&!vis[i]) cnt++;
		if(cnt>=m){
			for(int i=1;i<=n;i++) if(!(a[i]&(1<<k))) vis[i]=1;
			ans+=(1<<k);
		}
	}cout<<ans;
}/*
4 3
3 15 12 12
1111
1100
1100
*/ 