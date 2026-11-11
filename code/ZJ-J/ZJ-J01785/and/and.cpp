#include<bits/stdc++.h>
#define rd(x) cin>>x
#define pt(x) cout<<x
#define rep(i,x,y) for(ll (i)=(x);(i)<=(y);++i)
#define down(i,x,y) for(ll (i)=(x);(i)>=(y);--i)
#define rp(i,p) for(auto i:p)
#define mx(x,y) x=max(x,y)
#define mn(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int mod=1e9+7;
const int inf=1e9;
const ll linf=1e18;
ll n,m,cnt,now,res;
vector<ll> vec,lst;
void work(){
	rd(n),rd(m);
	rep(i,1,n) rd(now),vec.push_back(now);
	down(i,30,0){
		cnt=0;
		rp(j,vec) if(j&(1<<i)) ++cnt;
		if(cnt>=m){
//			pt("debug:"),pt(i),pt(' '),pt(cnt),pt('\n');
			lst.clear();
			rp(j,vec) if(j&(1<<i)) lst.push_back(j);
			vec.clear();
			rp(j,lst) vec.push_back(j);
//			pt("vec:");
//			rp(j,vec) pt(j),pt(' ');
//			pt('\n');
			if(cnt==m) break;
		}
	}
	res=vec[0];
	rep(i,1,m-1) res&=vec[i];
	pt(res);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int T;
	T=1;
//	rd(T);
	while(T--) work();
	return 0;
}
/*
4 2
3 15 12 12
*/
/*
5 3
31 3 1 15 7
*/
/*

*/
