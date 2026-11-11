#include<bits/stdc++.h>
#define int long long 
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define Rep(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
using namespace std;
const int N=2e6+10;

int n,d,a[N];
namespace sub {
	int f[N],g[N];
	int pre[N],suf[N];
	void solve() {
		int res=0;
		rep(i,1,n) {
			f[i]=0,g[i]=1;
			int R=n;
			rep(j,i+1,n) {
				f[j]=g[j]=0;
				int k=lower_bound(a+i,a+j+1,a[j]-d)-a;
				if (k==j) {
					R=j;
					break;
				}
				f[j]=f[k]+1,g[j]+=g[k];
				if (k+1<j and f[k]==f[k+1]) g[j]+=g[k+1];
				if (k+2<j and f[k]==f[k+2]) g[j]+=g[k+2];
			}
			rep(j,i+1,R) {
				res+=(g[j]==2);
			}
		}
		cout<<res<<endl;
		return ;
	}
}
int nxt[N],siz[N];
vector<int> e[N];
void solve() {
	cin>>n>>d;
	rep(i,1,n) cin>>a[i];
	if (n<=5000) {
		sub::solve();
		return ;
	}
	cout<<0<<endl;
//	rep(i,1,n-1) nxt[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
//	rep(i,1,n) siz[i]=1;
//	Rep(i,n-1,2) {
//		if (nxt[i]>nxt[i-1]) {
//			rep(j,nxt[i-1]+1,nxt[i]) if (j!=i) siz[i]+=siz[j];
//		}
//	}
//	rep(i,1,n) cout<<siz[i]<<" ";
//	cout<<endl;
//	int res=0;
//	vector<pii> vec;
//	Rep(i,n-1,1) {
//		if (nxt[i]<=i+1) continue;
//		int j=nxt[i];
//		if (nxt[j]>=nxt[j-1] and nxt[j-2]<nxt[j-1]) {
//			rep(k,nxt[j-2]+1,nxt[j-1]) {
//				cout<<i<<" "<<k<<endl;
//				res+=siz[k];
//			}
////			vec.eb(i,nxt[j-1]);
//		}
//	}
//	cout<<res<<endl;
	return ;
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,_;cin>>c>>_;
	while (_--) solve();
	return 0;
}
/*
一个小时两道题，这辈子没打过这么富裕的仗！
n^2 是简单的，40ts
直接枚举起点做 DP 即可。
先写个暴力观察下性质
暴力是对的
有一些是断崖，段内怎么做
以每个数为开头，这个都是连续的一段
1 1
18 20
398 399 420 424 432 438 439 450 452 457 463 466 469 476 483 487 490 493
1 1
100 20
1 13 15 22 31 34 35 43 45 50 55 60 63 65 75 78 88 92 93 105 116 120 122 123 124 132 137 144 155 175 176 181 182 186 193 194 195 199 201 204 206 211 217 218 222 226 232 236 237 265 270 276 280 282 286 288 294 304 308 310 311 312 315 317 318 327 328 329 332 339 341 345 348 350 361 362 364 371 386 390 392 394 398 399 420 424 432 438 439 450 452 457 463 466 469 476 483 487 490 493
考虑从后往前处理
每个点向它后面的最远的至多两个点连边
每个点有两种可能
i 能到的最远的点，i-1 到不了
这个时候 i 作为传递边
先看一下这个
这个是啥组成的呢？
首先是最基础的边
nmd 怎么没时间了
*/