#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,frt,bck;
ll m,a[N],q[N];
void solve(){
	frt=1,bck=0;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	ll nd=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		q[++bck]=a[i];
		nd+=(bck-frt)*(a[i]-a[i-1]);
		while(nd>m){
			nd-=a[i]-q[frt++];
		}
		ans=max(ans,bck-frt+1);
	}
	printf("%d\n",ans);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T=1;
	while(T--){
		solve();
	}
}
//ccf please let me AC!!!
