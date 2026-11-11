#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=500005;
ll a[MAXN],cf[MAXN];
//cf[i]-> 把i前所有数变为a[i]所用的能量 
ll n,m; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	} 
	sort(a+1,a+1+n);
	ll ans=0,sum=1,l=0;
    for(ll i=2;i<=n;i++){
        cf[i]=cf[i-1]+(i-1-l)*(a[i]-a[i-1]); 
    	sum++; 
    	while(cf[i]>m&&l<=i){
 	    	cf[i]=cf[i]-(a[i]-a[++l]);
	    	sum--;
	    }
	    ans=max(ans,sum);
   	}
    printf("%lld\n",ans);
	return 0;
	//解注释！！！！！！！ 
	//开long long !!! 
}

	
