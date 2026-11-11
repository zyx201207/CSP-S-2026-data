#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 5e5 + 10;
int __,_,n,m,d_,q;
int t[505][N],a[505][N];
int k[505];
int w[N],T;
bool vis1[N],vis2[N];
int be[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>__>>n>>m>>d_>>q;
	for(int i = 1;i <= m;++i)cin>>w[i];
	for(int i = 1;i <= n;++i){
		cin>>k[i];
		for(int j = 1;j <= k[i];++j){
			cin>>a[i][j]>>t[i][j];
			be[a[i][j]] = i;
			T = t[i][j];
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		int ans = w[u] + w[v];
		if(be[u] != be[v])ans += T;
		cout<<ans<<"\n";	
	}
}
/*
不是这个T2样例解释有问题，不早说，还有30min才说。白想了半天，CCF出题真有水准。 
*/
