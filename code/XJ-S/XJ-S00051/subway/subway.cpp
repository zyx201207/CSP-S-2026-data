#include<bits/stdc++.h>
using namespace std;
int w[500005];
int a[505][505];
struct Tra{
	int x;
	int y;
}t[100000];
int c,n,m,d,q;
int dfs(int Node,int end, int tsum){
	if(Node==end){
		return tsum;
	}
	int tmin=1e9;
	for(int i=0; i<n; i++){
		if(a[Node][i]!=0){
			tmin=min(tmin,dfs(i+1,end,w[Node-1]+a[Node][i]));
		}
	}
	
	return tmin;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>c>>n>>m>>d>>q;

	for(int i=0; i<m; i++){
		cin>>w[i];
	}
	
	int k;
	for(int i=1; i<=n; i++){
		cin>>k;
		int an,t;
		for(int j=1; j<=k; j++){
			cin>>an>>t;
			a[i][an]=t;
		}
	}
	
	for(int i=0; i<q; i++){
		cin>>t[i].x>>t[i].y;
	}
	
	for(int i=0; i<q; i++){
		cout<<dfs(t[i].x,t[i].y,0)<<'\n';
	}
	return 0;
}
