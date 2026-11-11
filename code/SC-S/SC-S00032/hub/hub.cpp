#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pr pair<int,int>
const int N=1e6+5;
int a[N];
struct node{
	int x,num;
}p[N][N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		vector<int>g[N];
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
			cout<<1<<endl;
		}
	}
	return 0;
} 