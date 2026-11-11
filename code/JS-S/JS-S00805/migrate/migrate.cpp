#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2000005;
int c,t,n,d,x[N],lst[N],nxt[N],f[N],g[N],ans;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;++i)cin>>x[i];
		lst[0]=nxt[0]=1;
		for(int i=1;i<=n;++i){
			lst[i]=lst[i-1],nxt[i]=nxt[i-1];
			while(x[i]-x[lst[i]]>d)++lst[i];
			while(x[nxt[i]+1]-x[i]<=d&&nxt[i]<n)++nxt[i];
		}
		for(int i=1;i<=n;++i){
			f[i]=g[i]=1;
			int a=i;
			for(;a!=nxt[a]&&lst[nxt[a]]==a;)++f[i],a=nxt[a];
			a=i;
			for(;a!=lst[a]&&nxt[lst[a]]==a;)++g[i],a=lst[a];
		}
		for(int i=1;i<=n;++i){
			int j=nxt[i];
			if(j>i+1&&nxt[j-1]>j&&lst[nxt[j-1]]==j-1)ans+=g[i]*f[nxt[j-1]];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
