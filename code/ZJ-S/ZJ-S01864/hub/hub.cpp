#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int N=514514,inf=10000007998244353;

int n,k;
vector <int > t[N];
int sz[N],mx,rt;
bool vis[N];

void solve() {
	int m;
	cin>>n>>k;
	for(int i=1; i<n; i++) {
		int u,v;
		cin>>u>>v;
	}
	m=(n-1)/2;
	if(k==n) cout<<0;
	else if(k>=m) cout<<1;
	else {
		int p1=(1.0*n/3.0+0.9),p2=(2.0*n/3.0+0.9);
		if(k<=2) cout<<max(max(p1+1,m-p2+1),(p1+p2)/2+1);
		else cout<<max(max(p1+1,m-p2+1),(p1+p2)/2+1)-k%4;
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
//	freopen("test.txt","r",stdin);
	freopen("hub5.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--) {
		solve();
		cout<<endl;
	}
	return 0;
}
