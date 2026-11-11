#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#define debug printf
#else
int debug(...){return 0;}
#endif
int n,m;
unsigned a[200005];
unsigned v=UINT_MAX;
bool vis[200005];
bool cmp(unsigned a,unsigned b){
	return __builtin_popcount(a)>__builtin_popcount(b) && a>b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
#ifndef LOCAL
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
#endif
	cin>>n>>m;
	
	for(int i=0;i<n;i++) cin>>a[i];
	//sort(a, a+n, cmp);
	for(int i=0;i<m;i++){
		unsigned mxav=0, mxbv=0;int mxp=0;
		for(int p=0;p<n;p++){
			if(!vis[p] && __builtin_popcount(v&a[p]) >= mxav && (v&a[p]) >= mxbv){
				mxav = __builtin_popcount(v&a[p]);
				mxbv = v&a[p];
				mxp = p;
			}
		}
		vis[mxp] = 1;
		
		v &= a[mxp];
	};
	cout << v;
	return 0;
}
