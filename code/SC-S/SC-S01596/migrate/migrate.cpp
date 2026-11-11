#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int c,t,n,nxt[N],f[N];
ll d,a[N],ans,sum[N],g[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	for(cin>>c>>t;t--;){
		cin>>n>>d;
		for(int i=1;i<=n;++i)
			cin>>a[i];
		for(int i=1;i<=n;++i)
			nxt[i]=upper_bound(a+1+i,a+1+n,a[i]+d)-a-1;
		ans=0;
		for(int i=1;i<=n;++i){
			f[i]=0;sum[i]=g[i]=1;sum[i+1]=0;
//			cout<<'#'<<i<<":\n";
			for(int j=i-1,pre=i;j;--j){
				int to=min(nxt[j],i);
				if(to==j)	break;
				f[j]=f[to]+1;
				if(f[j]>f[j+1])
					pre=j+1;
				g[j]=sum[pre]-sum[to+1];
				sum[j]=sum[j+1]+g[j];
				if(g[j]==2)	++ans;
//				cout<<j<<':'<<f[j]<<','<<g[j]<<'\n';
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}