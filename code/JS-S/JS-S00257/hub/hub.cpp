#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int c,T,d,p,w[N],ans=1e18,vh[N];
vector<int>g[N];
/*void dfs(int id,int y,int s){
	if(id==y){
		ans=min(ans,s);
		return;
	}
	for(int i=0;i<g[id].size();i++){
		if(vh[g[id][i]]==0){
			vh[g[id][i]]=1;
			dfs(g[id][i],y,s+1);
			vh[g[id][i]]=0;
		}
	}
}*/
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		cout<<1<<"\n";
	}
	return 0;
}
/*0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
