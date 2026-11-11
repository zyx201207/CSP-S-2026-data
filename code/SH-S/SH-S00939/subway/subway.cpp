#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,n,m,d,q,a[N],t[N][3];
vector<int> g[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	int t;
	for(int i=1;i<=n;i++){
		int k,x[3];
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x[i]>>t[i][j];
		}
		g[x[1]].push_back(x[2]);
		g[x[2]].push_back(x[1]);
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		long long s=a[x]+a[y];
		queue<int> q;
		for(int i:g[x]){
			q.push(i);
		}
		while(q.size()){
			int u=q.front();
			q.pop();
			for(int i:g[u]){
				
			}
		}
	}
}
