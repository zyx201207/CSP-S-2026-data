#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
ll cid,T,n,k,x,y,l,r,ans,cd[N],f[11],p[11],zrr;
vector<ll>g[N],c;
//void dfs(ll x,ll ls,ll d){
//	if(ans<=d){
//		ans=d;
//		y=x;
//	}
//	for(int i:g[x]){
//		if(i==ls) continue;
//		dfs(i,x,d+1);
//	}
//}
//bool fd(ll x,ll ls,ll d){
//	bool f=((x==l)||(x==r));
//	for(int i:g[x]){
//		if(i==ls) continue;
//		f|=fd(i,x,d+1);
//	}
//	if(f&&ans/2==d) c.push_back(x);
//	return f;
//}
//bool get(ll x,ll ls,ll d,ll k,ll &y){
//	bool f=((x==l)||(x==r));
//	for(int i:g[x]){
//		if(i==ls) continue;
//		f|=get(i,x,d+1,k,y);
//	}
//	if(f&&k==d) y=x;
//	return f;
//}
//void fdep(ll x,ll ls,ll d,ll &mx){
//	mx=max(mx,d);
//	for(int i:g[x]){
//		if(i==ls||cd[i]) continue;
//		fdep(i,x,d+1,mx);
//	}
//}
//bool sol(ll x,ll ls,ll d,ll k,ll e,ll lim,bool &fl){
//	bool f=(x==e);
//	for(int i:g[x]){
//		if(i==ls) continue;
//		f|=sol(i,x,d+1,k,e,lim,fl);
//	}
//	cd[x]=1;
//	if(!(x==e||!ls)){
//		ll res=0;
//		fdep(x,0,0,res);
//		if(res+min(d,k-d)>lim) fl=0;
//	}
//	return f;
//}
//bool check(ll mid){
//	ll x,y,len=ans-2*mid;
//	bool f=1;
//	get(l,0,0,mid,x);
//	get(r,0,0,mid,y);
//	sol(x,0,0,len,y,mid,f);
//	return f;
//}
void dfs(ll x,ll c,ll d){
	ans=max(ans,d);
	p[x]=1;
	for(int i:g[x]){
		if(p[x]||f[i]!=c) continue;
		dfs(i,c,d+1);
	}
}
void nonono(ll x,ll sum){
	if(sum>k) return;
	if(x>n){
		if(!sum) return;
		ll cnt=0;
		memset(p,0,sizeof(p));
		for(int i=1;i<=n;i++){
			if(f[i]&&!p[i]) cnt++,dfs(i,1,0);
		}
		if(cnt>2) return;
		ll mx=0;
		for(int i=1;i<=n;i++){
			if(f[i]){
				ans=0;
				memset(p,0,sizeof(p));
				dfs(i,0,0);
				mx=max(mx,ans);
			}
		}
		zrr=min(zrr,mx);
		return;
	}
	f[x]=0;
	nonono(x+1,sum);
	f[x]=1;
	nonono(x+1,sum+1);
} 
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>cid>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		for(int i=1;i<n;i++){
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		zrr=1e18;
		nonono(1,0);
		cout<<zrr<<"\n";
//		ans=0;
//		dfs(1,0,0);
//		l=y;
//		dfs(l,0,0);
//		r=y;
//		if(k==1){
//			c.clear();
//			fd(l,0,0);
//			ll mi=1e18;
//			for(int i:c){
//				ans=0;
//				dfs(i,0,0);
//				mi=min(mi,ans);
//			}
//			cout<<mi<<"\n";
//			continue;
//		}
//		if(k==2){
//			ll l=0,r=ans/2,mid;
//			while(l<r){
//				mid=l+r>>1;
//				if(check(mid)) r=mid;
//				else l=mid+1;
//			}
//			cout<<l<<"\n";
//			continue;
//		}
	}
	return 0;
}
//50min 0pts
//100+100+16+0<=216 我心态崩了
//退役！！数理化我来啦！！！ 
