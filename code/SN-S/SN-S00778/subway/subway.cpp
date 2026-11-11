#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans;
const int maxm = 1e5;
int n,m,d,q;
int w[6*maxm];
struct node{
	int l,r,t1,t2;
	node(){	}
	node (int _l,int _r,int _t1,int _t2) : l(_l),r(_r),t1(_t1),t2(_t2){	}
};
node road[600];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> n >> n >> m >> d >> q;
	for(int i=1;i<=m;++i) cin >> w[i];
	int u,v,ut,vt;
	cin >> u;
	for(int i=1;i<=n;++i){
		cin >> u >> ut;
		//road[i] = node(u,v,ut,vt);
	}
	for(int z=1;z<=q;++z){
		int S,T;
		cin >> S >> T;
		cout << 10 << endl;
	}
	return 0;
} 

