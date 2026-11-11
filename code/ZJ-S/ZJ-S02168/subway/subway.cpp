//test 
#include<bits/stdc++.h>
#define int long long
#define For(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int c,n,m,d,q,ans;
int w[1005];

struct edge{
	int v,w;
};

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>>c>>n>>m>>d>>q;
	For(i, 1, n){
		cin>>w[i];
		ans += w[i];
	}
	while(q--){
		cout<<ans;
	}
	return 0;
}
