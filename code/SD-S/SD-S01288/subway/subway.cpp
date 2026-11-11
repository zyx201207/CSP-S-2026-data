#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lowbit(x) ((x)&(-(x)))
#define mask ((ull)(-1))
inline ll read(){
	ll x=0;char c=getchar();bool f=0;
	for(;c<'0'||c>'9';c=getchar()) f|=(c=='-');
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	return f?-x:x;
}
ll w[500010],k[510];
vector<ll> arr[510];


const int N=7900;
struct bit{
	ull bits[N];
	bit operator |(bit a)const{
		for(int i=0;i<N;i++) a.bits[i]|=bits[i];
		return a;
	}
	bit operator &(bit a)const{
		for(int i=0;i<N;i++) a.bits[i]&=bits[i];
		return a;
	}
	bool any(){
		for(int i=0;i<N;i++) if(bits[i]) return true;
		return false;
	}
	void set(ll x){
		bits[x>>6]|=(1ull<<(x&mask));
	}
	ll get(ll x){
		return (bits[x>>6]>>(x&mask))&1ull;
	}
};

bit sta[510];
//bitset<500010> sta[510],o;
inline ull lgg(ull x){
	ll cnt=0;
	while(x>>=1) cnt++;
	return cnt;
}
#define pll pair<ll,ll>
#define mkpr make_pair
map<pll,ll> tim;
vector<pll> mp[1000010];
ll node_cnt;
ll dis[1000010],mk[1000010];
priority_queue<pll,vector<pll>,greater<pll> > q;
inline ll dijkstra(ll st,ll ed,ll n){
	while(!q.empty()) q.pop();
	for(ll i=1;i<=n;i++) dis[i]=1e18,mk[i]=0;
	dis[ed]=1e18;
	q.push(mkpr(0,st));
	while(!q.empty()){
		pll o=q.top(); q.pop();
		ll noww=o.second,diss=o.first;
		if(noww==ed) return dis[ed];
		if(mk[noww]) continue;
		mk[noww]=1;
		ll siz=mp[noww].size();
		for(ll i=0;i<siz;i++){
			ll nex=mp[noww][i].first,w=mp[noww][i].second;
			if(dis[nex]>dis[noww]+w){
				dis[nex]=dis[noww]+w;
				q.push(mkpr(dis[nex],nex));
			}
		}
	}
	return 1e18;
}
int main(){ 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll testid=read();
	ll n=read(),m=read(),d=read(),q=read();
	// xian     dian     max      query
	for(ll i=1;i<=m;i++) w[i]=read();
	for(ll i=1;i<=n;i++){
		k[i]=read();
		for(ll j=1;j<=k[i];j++){
			ll a=read(),t=read();
			sta[i].set(a);
			
			arr[i].push_back(a);
//			tim[i].push_back(t);
			tim[mkpr(i,a)]=t;
		}
	}
//	cout<<sta[1].bits[0]<<" "<<sta[2].bits[0]<<"\n";
	for(ll i=1;i<n;i++){
		for(ll j=i+1;j<=n;j++){
//			cout<<"trying"<<i<<" "<<j<<"\n";
			bit o=sta[i]&sta[j];
			if(o.any()){
				for(int p=0;p<N;p++){
					if(!o.any()) break;
					while(o.bits[p]){
//						cout<<o.bits[p]<<"\n";
						ll k=lowbit(o.bits[p]);
						o.bits[p]-=k,k=lgg(k)+(p<<6);
						ll val=tim[mkpr(i,k)]+tim[mkpr(j,k)];
						mp[i].push_back(mkpr(j,val));
						mp[j].push_back(mkpr(i,val));
//						cout<<i<<" "<<j<<" "<<k<<" "<<val<<"\n";
					}
				}
			}
		}
	}
//	cout<<"ok";
	node_cnt=n;
	while(q--){
		ll xx=read(),yy=read();
//		cout<<"#1 ";
		ll cnt=w[xx]+w[yy];
		ll st=++node_cnt,ed=++node_cnt;
		for(ll i=1;i<=n;i++){
			if(sta[i].get(xx)) mp[st].push_back(mkpr(i,tim[mkpr(i,xx)]));
			if(sta[i].get(yy)) mp[i].push_back(mkpr(ed,tim[mkpr(i,yy)]));
		}
		printf("%lld\n",dijkstra(st,ed,n)+cnt);
	}
	return 0;
}
