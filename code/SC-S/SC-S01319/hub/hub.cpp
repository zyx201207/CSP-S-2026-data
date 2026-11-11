#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL c,t,n,k;const int N=2e6+100;
LL v[N],u[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&k);
		for(int i=2;i<=n;i++){
			scanf("%lld%lld",&u[i],&v[i]);
		}
	}
}