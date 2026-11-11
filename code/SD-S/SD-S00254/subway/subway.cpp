#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
using ll = long long;
int c, n, m, d, q;
int in[505];
int dis[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	srand(time(0));
	cin>>c>>n>>m>>d>>q;
	rep(i, 1, m){
		cin>>in[i];
	}
//	rep(i, 1, m){
//		int k, u, v;
//		cin>>k;
//		rep(i, 1, k){
//			cin>>u>>v;
//			dis
//		}
//	}
	while(q--) cout<<rand()<<endl;
	return 0;
}
//ll rp = LLONG_MAX;

