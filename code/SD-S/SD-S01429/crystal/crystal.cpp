#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll maxn=5e5+10;
ll a[maxn];
ll ans=0;ll n;ll m;
inline ll read(){
	ll r=0;ll f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-'){
			f=-1;
		}c=getchar();
	}while(isdigit(c)){
		r=r*10+(c-'0');
		c=getchar();
	}return r*f;
}
ll cnt=0;
bool check(ll mid){
	priority_queue<ll> pq;
	ll tot=0;cnt=0;
	for(ll i=1;i<=mid;i++){
		tot+=a[mid]-a[i];
		pq.push(a[mid]-a[i]);
		cnt++;
		
	}while(tot>m&&!pq.empty()){
			//printf("%lld %lld ",tot,pq.top());////////
			tot-=pq.top();
			pq.pop();
			cnt--;
	}
	//printf("mid=%lld tot=%lld cnt=%lld\n",mid,tot,cnt);//////
	return tot<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(ll i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	ll l=1,r=n;
	while(l<=r){
		ll mid=l+(r-l)/2;
		if(check(mid)){
			//printf("%lld %lld\n",mid,cnt);/////////////////////
			ans=max(ans,cnt);
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	printf("%lld\n",ans);
	return 0;
} 
