#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5,INF=1e18;
int c,n,m,d,q,w[M],k,mn,x,y,A,B;
vector<pair<int,int> > e[M+N];
void dij(int s,int fa,int val){
	if(val>=mn) return;
	if(s==y) mn=min(mn,val);
	for(auto v:e[s]) {
		if(v.first==fa) continue;
		dij(v.first,s,val+v.second);
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int np=m+i;
		cin>>k;
		while(k--){
			cin>>A>>B;
			e[np].emplace_back(A,B);
			e[A].emplace_back(np,B);
		}
	}while(q--){
		mn=INF;
		cin>>x>>y;
		dij(x,0,0);
		int ans=w[x]+w[y]+mn;
		cout<<ans<<"\n";
	} 
	return 0;
} 
