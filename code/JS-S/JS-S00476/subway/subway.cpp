#include <bits/stdc++.h>
using namespace std;
struct Node{
	int v,id,t;
}
vector<Node> e[500005];
int c,n,m,d,q,w[500005],dis[500005],vis[500005];
int main(){
	//Holy shit
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		cin>>w[i];
	}
	for(int i = 1;i<=n;i++){
		int k,last = 0;
		cin>>k;
		for(int j = 1;j<=k;j++){
			int a,t,time;
			cin>>a>>t;
			if(j > 1){
				e[a].push_back(last,i,t);
				e[last].push_back(a,i,time);
			}
			last = a;
			time = t;
		}
	}
	for(int i = 1;i<=q;i++){
		int x,y;
		cin>>x>>y;
	}
}