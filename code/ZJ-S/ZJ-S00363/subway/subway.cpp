#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
int c,n,m,d,q,w[N],dfsans,t[N][N],a[N];
int l,r;
struct Node{
	int v,xian;
};
vector<Node> e[N];
vector<int> x[N];
void dfs(int u,int xi,int sum,int notgo){
	if(sum>dfsans) return;
	if(u==r){
		dfsans=min(dfsans,sum+t[xi][u]);
		return;
	}
	for(Node temp:e[u]){
		int v=temp.v,xian=temp.xian;
		if(v==notgo) continue;
		if(xian==xi){
			dfs(v,xi,sum,u);
		}else{
			dfs(v,xian,sum+t[xi][u]+t[xian][u],u);
		}
	}
}
signed main(){
//	system("fc subway4.out subway4.ans");
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int temp;
			cin>>a[j]>>temp;
			t[i][a[j]]=temp;
			x[a[j]].push_back(i);
			e[a[j-1]].push_back({a[j],i});
			if(j!=1) e[a[j]].push_back({a[j-1],i});
		}
	}
	while(q--){
		cin>>l>>r;
		int ans=LLONG_MAX;
		for(int xi:x[l]){
			dfsans=LLONG_MAX;
			dfs(l,xi,t[xi][l],0);
			ans=min(ans,dfsans);
		}
		cout<<ans+w[l]+w[r]<<'\n';
	}
}
