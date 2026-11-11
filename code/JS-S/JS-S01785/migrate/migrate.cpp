#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,T,subs[505][505],w[500005],t1,t2,t3,t4,cnt;
int check(ll l,ll r){
    if(w[r]-w[l]<=m)return 1;
    int ans=0;
    for(int i = l+1,t=1000000000;i<=r;i++){
		t1=check(l,i)*check(i+1,r);
		if(t1<=t){
			ans=(t1==t)*ans+1;
			t=t1;
		}
	}
	if(ans==2)cnt++;
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--){
		cnt=0;
	    scanf("%lld%lld",&n,&m);
	    for(int i=1;i<=n;i++)
			scanf("%lld",&w[i]);
		printf("%lld\n",cnt);
	}
}


