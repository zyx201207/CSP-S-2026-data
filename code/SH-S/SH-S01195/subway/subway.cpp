#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,mm[500010],ans;
struct node{
	int to,w;
};
vector<node> q[500010];
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>mm[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,v;
			cin>>u>>v;
			q[i].push_back({u,v});
		}
	}
	cout<<ans; 
	
} 
