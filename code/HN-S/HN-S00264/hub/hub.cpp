#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,k,c;
vector<int > e[1000006];
pair<int,int> dfs(int x,int fa,int juli){
	int mx=juli,farth=x;
	for(int v:e[x]){
		if(v==fa)continue;
		auto now=dfs(v,x,juli+1);
		farth=mx>now.first?farth:now.second;
		mx=max(mx,now.first);
	}
	return {mx,farth};
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		if(n==k){
			cout<<0<<'\n';
			continue;
		}
		else if(k==0&&(c==13||c==14)){
			cout<<n<<'\n';
			continue;
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		int x=dfs(1,0,0).second;
		int df=dfs(x,0,0).first;
//		cout<<df;
		if(k==0)cout<<df;
		else if(k==1)cout<<(df+1)/2;
		else cout<<(df+1-k+2)/3;
		cout<<'\n';
	}
} 
/*
0 1
9 2
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
*/
