#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+7;
int n,d,a[N],nx[N],cnt[N],f[N],g[N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;++i) nx[i]=cnt[i]=f[i]=g[i]=0;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1,j=1;i<=n;++i){
		while(j<=n&&a[j]<=a[i]+d) ++j;
		nx[i]=j-1;
		cnt[i]=nx[i]-nx[i-1];
	}
	for(int i=1;i<=n;++i){
		if(!cnt[i]) f[i]=0;
		++f[i];
		f[nx[i]]+=f[i];
	}
	for(int i=n;i>=1;--i){
		g[i]=cnt[i];
		if(cnt[i]) g[i]+=g[nx[i]];
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		if(nx[i]<=i+1) continue;
		int t=nx[i]-1,x=0,y=0;
		x=cnt[t];
		if(cnt[t]&&nx[nx[i]]==nx[t])
			x+=g[nx[t]];
		if(nx[i-1]>=t) y=1;
		else y=f[i];
		ans+=x*y;
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T>>T;
	while(T--) solve();
	return 0;
}
