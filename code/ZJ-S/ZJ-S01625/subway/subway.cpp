#include<bits/stdc++.h>
using namespace std;
//#define int long long
int c,n,m,d,p;
const int M=5e5;
int w[M],t[M][505];
struct node{
	int v;
	long long o;
	friend bool operator < (node a,node b){
		return a.o<b.o;
	}
};
vector<int> g[M][505];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	if(n<=50){
		for(int i=1;i<=n;i++){
			int k,a,b;
			cin>>k;
			vector<int> sp;
			for(int j=1;j<=k;j++){
				cin>>a>>b;
				for(auto x:sp){
					g[a][i].push_back(x);
					g[x][i].push_back(a);
				} 
				sp.push_back(a);
				t[a][i]=b;
			}
		}
		while(p--){
			int x,y;
			priority_queue<node> q;
			q.push({x,0ll});
			vector<long long> dis(m+1,2e10);
			while(!q.empty()){
				node u=q.top();
				q.pop();
				if(u.o>dis[u.v]){
					continue;
				}
				for(int i=1;i<=n;i++){
					
				}
			}
		}
	}
	
	
	return 0;
}
/*

*/
