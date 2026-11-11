#include<bits/stdc++.h>
using namespace std;
const int N =5e5+10;
int tielu[30][N],k[30],w[N],t[30][N];
vector<int> a[N];
int c,n,m,d,q;
int x,y;
long long ans=1e18;
bool v[100],v1[N];
void dfs(int o,long long sum){
	if(v1[o]) return;
	if(o==y){
		ans=min(ans,sum);
		return;
	}
	v1[o]=true;
	for(int i=0;i<a[o].size();i++){
		int lu=a[o][i];
		if(v[lu])
			continue;
		v[lu]=true;
		for(int j=1;j<=k[lu];j++){
			dfs(tielu[lu][j],sum+t[lu][j]+t[lu][o]);
		}
		v[lu]=false;
	}
	v1[o]=false;
}
int main(){	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>tielu[i][j]>>t[i][j];
			a[tielu[i][j]].push_back(i);
		}
	}
	while(q--){
		ans=1e18;
		cin>>x>>y;
		dfs(x,0);
		long long shijian=w[x]+w[y]+ans;
		cout<<shijian<<"\n";
	}
	return 0;
}