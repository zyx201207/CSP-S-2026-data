#include<bits/stdc++.h>
#define int long long
using namespace std;
struct yc{
	int line,t;
};
vector<yc> e[500005];
int c,n,m,d,q,w[500005],e1[305][305];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int st,ed,k;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			e[a].push_back({i,t});
		}
	}
	memset(e1,0x3f,sizeof(e1));
	for(int i=1;i<=n;i++){
		e1[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		if(e[i].size()>1){
			for(yc l1:e[i]){
				for(yc l2:e[i]){
					if(l1.line!=l2.line){
						e1[l1.line][l2.line]=l1.t+l2.t;
					}
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				e1[i][j]=min(e1[i][j],e1[i][k]+e1[k][j]);
			}
		}
	}
	while(q--){
		cin>>st>>ed;
		int ans=0x3f3f3f3f;
		for(auto l1:e[st]){
			for(auto l2:e[ed]){
				ans=min(ans,l1.t+l2.t+e1[l1.line][l2.line]);
			}
		}
		cout<<ans+w[st]+w[ed]<<"\n";
	}
}