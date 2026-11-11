#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=5*1e5+200;
const int N=1e5+200;
ll c,n,m,d,q;
ll x,y;
ll w[M];
ll a[M],t[M];
struct s{
	vector<ll> p;
	ll t;
	int luxian;
}o[N];
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
ll found(ll id,ll k,bool start){
	pq.pop();
	ll g;
	int l;
	if(start==true) k+=w[id];
	ll kk=k;
	for(int i=1;i<=int(o[id].p.size());i++){
		k=kk;
		g=o[id].p[i];
		l=o[id].luxian;
		k+=t[l];
		pq.push({k,g});
		if(g!=y) found(g,k,false);
	}
	return k;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	int k;
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%lld %lld",&a[j],&t[j]);
			if(j!=1) o[a[j-1]].p.push_back(a[j]);
			if(o[a[j]].luxian==0) o[a[j]].luxian=i;
			else o[a[j]].luxian=-1;
		}
	}
	while(q--){
		scanf("%lld %lld",&x,&y);
	    printf("%lld",found(x,0,true));
	}
	return 0;
}
