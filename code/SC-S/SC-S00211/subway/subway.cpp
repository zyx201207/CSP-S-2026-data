#include<bits/stdc++.h>
using namespace std;
const int N=5*10e5+10;
long long n,m,c,d,q;
long long w[N];
vector<pair<long long,long long> >g[N];
void dfs(int x,int y){
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	while(n--){
		int u,w;
		cin>>k;
		for(int i=0;i<k;i++){
			int a,t;
			cin>>a>>t;
			if(i!=0){
				g[u].push_back({a,t+w});
				g[a].push_back({u,t+w});
			}
			u=a;
			w=t;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dfs(x,y);
	}
	return 0;
}