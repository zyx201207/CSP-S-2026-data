#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int x[N];
vector<int> g[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		for(int i=0; i<N; ++i) g[i].clear();
		int n,d;
		cin>>n>>d;
		for(int i=1; i<=n; ++i) cin>>x[i];
		int l=1,r=2;
		while(r<=n){
			while(x[r]-x[l]>d) ++l;
			for(int i=l; i<r; ++i){
				g[i].push_back(r);
			}
			++r;
		}
		long long ans=0;
		for(int i=1; i<=n; ++i) if(g[i].size()==2) ++ans;
		cout<<ans<<'\n';
	}
	return 0;
}
