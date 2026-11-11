#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
vector<int> G[N];
int n,k,c,t,lis[N],fa[N];
int fin(int x){
	if(x==fa[x]) return x;
	return fa[x]=fin(x);
}
signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v; cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		cout<<rand()%n<<endl;
	}
	return 0;
}
