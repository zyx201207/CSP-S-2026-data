#include<bits/stdc++.h>
using namespace std;
#define int long long
int FW_number,n,m,d,q,w[500010];
vector<int>T[500010],W[500010];
int e[510][510];
signed main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>FW_number>>n>>m>>d>>q;
	memset(e,0x3f,sizeof e);
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int x,t;
			cin>>x>>t;
			T[x].push_back(i),W[x].push_back(t);
		}
		e[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<T[i].size();j++) for(int k=0;k<T[i].size();k++)
			e[T[i][j]][T[i][k]]=min(e[T[i][j]][T[i][k]],W[i][j]+W[i][k]);
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
	while(q--){
		int x,y,ans=4e18;
		cin>>x>>y;
		for(int j=0;j<T[x].size();j++) for(int k=0;k<T[y].size();k++)
			ans=min(ans,w[x]+W[x][j]+w[y]+W[y][k]+e[T[x][j]][T[y][k]]);
		cout<<ans<<"\n";
	}
	return 0;
}
// 14:48 会 T2 
// 本题是个读题题 
// 放 24 年说不定我都能切掉 
// 今年 CSP-S 是往简单的出的 
// 14:54 写完 