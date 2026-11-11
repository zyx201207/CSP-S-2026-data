#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+10;
int n;
ll m;
ll a[maxn];
ll ans;
void Read(){
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
}
void Sol(){
	sort(a+1,a+1+n);
	ll d=a[2]-a[1],cost=0,x=0;
	for(int i=1;i<=n;++i){
		x+=i;
		cost=d*x;
		if(cost>m){
			ans=i;
			break;
		}
		if(i==n) ans=n;
	}
	printf("%lld",ans);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	Read();
	Sol();
	return 0;
}