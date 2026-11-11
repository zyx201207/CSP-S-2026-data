#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e6+5;
int n,a[N],f[N],m,g[N],ans,T,C;
void solve1(){
	ans=0;
	for(int now=1;now<=n;now++){
		for(int i=1;i<=n;i++) f[i]=1e9,g[i]=0;
		f[now]=0,g[now]=1;
		for(int i=now+1;i<=n;i++) {
			for(int j=now;j<i;j++){
				if(a[i]-a[j]>m) continue;
				if(f[j]+1==f[i]) g[i]+=g[j];
				if(f[j]+1<f[i]) f[i]=f[j]+1,g[i]=g[j];
			}

		}
		for(int j=now+1;j<=n;j++){
			if(g[j]==2) ans++;
			// cout<<j<<' '<<f[j]<<' '<<g[j]<<'\n';
		}
	}
	cout<<ans<<'\n';
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--) {
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		solve1();
	}
	

	return 0;
}
/*
权值线段树动态开点，因为a[i] \in [-1e18,1e18]
*/