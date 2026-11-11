#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6;
int f[N],c,t,g[N];
int a[N],lst[N],n,d,ans,h[N],D[N];
namespace P1 {
	void solve() {
		for(int i=1; i<=n; i++) {
			for(int j=1;j<=n;j++)f[j]=g[j] = h[j] = D[j] =0;
			f[i] = 1;
			g[i] = 1;
			h[i] = 0;
			D[0] = i;
			for(int j=i+1,k=j+1; j<=n; j++) {
				f[j] = max(0ll,g[D[h[lst[j]]]] - g[lst[j]-1]);
				//	cout<<lst[j]<<" "<<D[h[lst[j]]]<<endl;
				if(f[j]==2)ans++;
				//	if(f[j]>2)break;
				g[j] = g[j-1] + f[j];
				h[j] = h[max(lst[j],i)] + 1;
				D[h[j]] = j;
				//	cout<<f[j]<< " ";
			}//cout<<endl;
			//	cout<<ans<<endl;
			//
		}
		cout<<ans<<endl;
	}
}
namespace P2{
	void solve(){
		int  D = a[2]  -a[1];
		if(D >=d ){
			printf("%lld\n",0);
			return ;
		}
		int t = d/D;
		for(int i=1;i<=n;i++){
			if(i+t*2-1<=n)ans++;
		}
		printf("%lld\n",ans);
	}
}
signed main() {
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	scanf("%lld%lld",&c,&t);
	while(t--) {
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1; i<=n; i++)
			scanf("%lld",&a[i]);
		for(int i=1,j=1; i<=n; i++) {
			while(a[i] - a[j] > d)j++;
			lst[i] = j;
		}
		if(n<=5000) {
			P1::solve();
			continue;
		}
		int D = a[2] - a[1];
		int flag=1;
		for(int i=2;i<n;i++){
			if(D !=a[i+1] - a[i]){
				flag=0;
			}
		}
		if(flag){
			P2::solve();
			continue;
		}
	}

	return 0;
}