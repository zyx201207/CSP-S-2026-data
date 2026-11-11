#include<bits/stdc++.h>
using namespace std;
const long long N=2*1e6+5;
long long c,t,sum[N],a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,d;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(d>=a[n]-a[1]){
			cout<<0<<endl;
			continue;
		}
	}
	return 0;
}