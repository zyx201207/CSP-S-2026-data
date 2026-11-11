#include<bits/stdc++.h>
using namespace std;
#define ll  long long
const int N=5e5+10;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	ll rt=0;
	int res=1,l=1;
	for(int i=1;i<=n;i++){
		rt+=(a[i]-a[i-1])*1ll*(i-l);
		while(rt>m){
			rt-=(a[i]-a[l++]);
		}
		res=max(res,i-l+1);
	}
	printf("%d\n",res);
	return 0;
}
