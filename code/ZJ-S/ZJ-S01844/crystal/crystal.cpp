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
const int N=5e5+10;
const int mod=1e9+7;
const int inf=1e9;
const ll linf=1e18;
ll n,m,L,R,mid,res;
ll num[N],sum[N];
bool check(ll lim){
	rep(i,1,n-lim+1){
		ll r=i+lim-1;
		if(num[r]*lim-(sum[r]-sum[i-1])<=m) return true;
	}
	return false;
}
void work(){
	rd(n),rd(m);
	rep(i,1,n) rd(num[i]);
	sort(num+1,num+1+n);
	rep(i,1,n) sum[i]=sum[i-1]+num[i];
//	rep(i,1,100) pt(num[i]),pt(' ');
//	pt('\n');
//	rep(i,1,100) pt(sum[i]),pt(' ');
//	pt('\n');
	L=1,R=n;
	while(L<=R){
		mid=(L+R)>>1;
		if(check(mid)) res=mid,L=mid+1;
		else R=mid-1;
	}
	pt(res),pt('\n');
//	rep(i,1,n-res+1){
//		ll r=i+res-1;
//		if(num[r]*res-(sum[r]-sum[i-1])<=m){
//			pt(i),pt(' '),pt(r),pt('\n'),pt(num[i]),pt(' '),pt(num[r]),pt(' '),pt(sum[r]-sum[i-1]),pt(' '),pt(num[r]*res-(sum[r]-sum[i-1])),pt(' '),pt(m),pt('\n');
//		}
//	}
}
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T;
	T=1;
//	rd(T);
	while(T--) work();
	return 0;
}
/*
5 5
1 2 4 8 9
*/
/*
5 8
-3 -1 2 2 7
*/
/*

*/