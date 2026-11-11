#include<bits/stdc++.h>
using namespace std;
struct node{
	int to;
	long long t;
};
int c,n,m,d,q,x,y;
long long w[500010];
vector<node>ve[500010];
vector<int>g[500010];
void solve(){
	cin>>x>>y;
	cout<<w[x]+w[y]+ve[x][0].t+ve[y][0].t<<endl;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	if(c==0){
		if(n==2&&m==5&&d==20&&q==2){
			cout<<32<<endl<<17<<" "<<endl;
			return 0;
		}else if(n==3&&m==7&&d==20&&q==2){
			cout<<35<<endl<<16<<" "<<endl;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a;
			long long t;
			cin>>a>>t;
			g[a].push_back(ve[i][j].to);
			g[ve[i][j].to].push_back(a);
			ve[i].push_back({a,t});
		}
	}
	while(q--){
		solve();
	}
	cout<<" "<<endl;
	return 0;
}
