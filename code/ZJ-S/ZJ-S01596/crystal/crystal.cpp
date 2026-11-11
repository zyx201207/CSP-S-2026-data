#include<bits/stdc++.h>
#include<ctime>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],b[N];
int ans;
bool Check(int len){
	for(int i=len;i<=n;++i)
		if(a[i]*len-(b[i]-b[i-len]) <= m)
			return true;

	return false;
}
void solve(){

	ans=0;
	cin>>n>>m;

	for(int i=1;i<=n;++i)
		cin>>a[i];

	sort(a+1,a+1+n);

	for(int i=1;i<=n;++i)
		b[i]=b[i-1]+a[i];

	int L=1,R=n;

	while(L<R){
		int mid=(L+R)>>1;
		if(Check(mid)) L=mid+1,ans=max(ans,mid);
		else R=mid-1;
	}

	if(Check(L)) ans=max(ans,L);

	cout<<ans<<"\n";

	return;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	int T=1;
	// cin>>T;
	while(T--) solve();

	// cerr<<1e3*clock()/CLOCKS_PER_SEC<<"ms\n";
	return 0;
}