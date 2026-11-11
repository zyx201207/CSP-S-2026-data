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
const int M=3e5+10;
const int mod=1e9+7;
const int inf=1e9;
const ll linf=1e18;
ll n,m,pos;
ll num[N],lst[M];
ll res[M];
void work(){
	rd(n),rd(m);
	rep(i,1,n) rd(num[i]),lst[num[i]]=i;
	rep(i,1,n){
		pos=i;
//		pt("#"),pt(i),pt('\n');
		while(pos<=n){
//			pt(pos),pt(' '),pt(num[pos]),pt('\n');
			++res[num[pos]];
			if(pos==n) break;
			pos=lst[num[pos]]+1;
		}
	}
	rep(i,1,m) pt(res[i]),pt(' ');
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int T;
	T=1;
//	rd(T);
	while(T--) work();
	return 0;
}
/*

*/
/*
4 3
1 2 1 3
*/
/*

*/
