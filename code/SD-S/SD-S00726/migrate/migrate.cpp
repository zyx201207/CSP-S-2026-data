#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n,d,a[N],f[N];
long long ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<n;++i)
			f[i]=upper_bound(a+i,a+n+1,a[i]+d)-a-1-i;
		for(int i=2;i<n;++i)ans+=f[i]==f[i-1];
		cout<<ans<<'\n';
	}
	return 0;
}
