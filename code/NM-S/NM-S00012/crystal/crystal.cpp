#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef __int128 ll;
vector<ll> a, d;
struct sta{
	ll y, x;
};
vector<sta> st;
ll n, m, nowm=0;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	LL tn, tm;
	cin>>tn>>tm;
	n=tn;
	m=tm;
	a.resize(n);
	d.resize(n+1);
	for(ll i=0; i<n; i++){
		LL tmp;
		cin>>tmp;
		a[i]=tmp;
	}
	sort(a.begin(), a.end());
	d[0]=a[0];
	for(ll i=1; i<n; i++){
		d[i]=a[i]-a[i-1];
	}
	st.push_back({0, d[0]});
	for(ll i=1; i<n; i++){
		if(d[i]!=0){
			st.push_back({i, a[i]});
		}
	}
	st.push_back({n, 1e18+1});
	ll nowm=0, maxans=st[1].y, lasty=0, lastx=0;
	queue<ll> q;
	q.push(0);
	for(int i=0; i<st.size(); i++){
//		printf("st[%d]:y=%d, x=%d\n", i, (LL)st[i].y, (LL)st[i].x);
	}
	for(ll i=1; i<st.size()-1; i++){
//		printf("i=%d, nowm=%lld, maxans=%lld, lasty=%lld, lastx=%lld\n", (LL)i, (LL)nowm, (LL)maxans, (LL)lasty, (LL)lastx);
		q.push(i);
		ll basey=st[i+1].y;
		ll more=(st[i].x-st[i-1].x)*(st[i].y-lasty);
		nowm+=more;
//		printf("v1=%lld, v2=%lld\n", (LL)(st[i].x-st[i-1].x), (LL)(st[i].y-lasty));
		ll need=nowm-m;
		if(need<=0){
//			printf("goto b: basey:%d\n", (LL)basey);
			maxans=max(maxans, basey);
			continue;
		}
//		printf("need=%lld\n", (LL)need);
		while(!q.empty()){
			ll now=q.front();
//			printf("now:%d\n", (LL)now);
			ll candel=(st[now].y-lasty)*(st[i].x-lastx);
//			printf("nowm:%d, candel:%d\n", (LL)nowm, (LL)candel);
			if(nowm-candel >=m){
//				printf("hit %d\n", (LL)(nowm-candel));
				nowm-=candel;
				q.pop();
				lasty=st[now].y;
				lastx=st[now].x;
				continue;
			}
			nowm-=candel;
			ll tar=m-nowm;
//			printf("tar:%d\n", (LL)tar);
			ll lines=tar/(st[i].x-lastx);
//			printf("lines:%d\n", (LL)lines);
			nowm+=lines*(st[i].x-lastx);
//			printf("nowm:%d\n", (LL)nowm);
			lasty=st[now].y-lines;
//			printf("st[now].y:%d\n", (LL)st[now].y);
			break;
		}
		maxans=max(maxans, basey-lasty);
	}
	cout<<(LL)maxans;
	return 0;
} 
