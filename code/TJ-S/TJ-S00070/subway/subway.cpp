#include<bits/stdc++.h>
#define rep(a,b) for(int i=(a); i<=(b); ++i)
#define per(a,b) for(int i=(b); i>=(a); ---i)
#define ll long long
using namespace std;
const int MAXN = 0x3f3f3f3f;
const int N = 550;
const int M = 5e5+10;
const int Q = 1e5+10;
int c, n, m, d, q;
int w[M], k[N], a[N], t[N], x[Q], y[Q];

//1-6暴力 （24） 
//7-11 A dijstra（20） 
//12-19 B 换乘代价相同（32） 
//20-21 只有两条线路（8） 
//22-23 每个站只有一种换乘方式（8） 
//24-25 正解 （8） 

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> n >> m >> d >> q;
	rep(1,m) cin >> w[i];
	rep(1,n){
		cin >> k[i];
		rep(1,2*k[i]){
			cin >> a[(i+1)/2] >> t[(i+1)/2];
		}
	}
	rep(1,q){
		cin >> x[i] >> y[i];
	}
	
	rep(1,q) cout << 0 << '\n';
	return 0;
}
