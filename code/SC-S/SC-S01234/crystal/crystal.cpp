#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
namespace my{
	const ll maxn=5e5+10;
	ll n,m,a[maxn],d[maxn];
	int main(){
		freopen("crystal2.in","r",stdin);
		freopen("crystal2.out","w",stdout);
		scanf("%lld%lld",&n,&m);
		bool flag=1;
		//cerr<<n<<" "<<m<<endl;
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(a[i]!=i)flag=0;
		}if(flag){
			ll pre[maxn]={0};
			for(int i=1;i<=n;i++)
				pre[i]=a[i]+pre[i-1];
			for(int i=1;i<=n;i++)
				if(pre[i]>m)cout<<i-1;
			return 0;
		}
		sort(a+1,a+n+1);
		//for(ll i=1;i<=n;i++)
		//	cerr<<a[i]<<endl;
		for(ll i=1;i<=n;i++)
			d[i]=a[i]-a[i-1];
		ll tot=0;
		for(ll i=1;i<=n;i++){
			tot+=d[i]*(i-1);
		//	cerr<<tot<<" "<<i<<endl;
			if(tot>=m&&i+1<=n&&a[i+1]!=a[i]){
				ll ans=((tot>m)?i-1:i);
				printf("%lld",ans);
				return 0;
			}
		}
		return 0;
	}
}
int main(){
	my::main();
	return 0;
}