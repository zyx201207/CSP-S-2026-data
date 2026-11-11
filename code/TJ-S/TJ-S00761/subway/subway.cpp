#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans,w[500005];
int k[505];
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

struct node{
	int v;
	int val;
};
vector<node> a[500005];
void dfs(int x,int fa,int end,int stp){
	if(x==end){
		ans=min(ans,stp);
		return;
	}
	for(int i=0;i<a[x].size();i++){
		if(a[x][i].v==fa) continue;
		dfs(a[x][i].v,x,end,stp+a[x][i].val);
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int cnt=m;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int x,y,lst=0;
		for(int j=1;j<=k[i];j++){
			cin>>x>>y;
			a[x].push_back({++cnt,y});
			a[cnt].push_back({x,y});
			if(lst) a[lst].push_back({cnt,0});
			lst=cnt;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=INT_MAX;
		dfs(x,-1,y,0);
		cout<<ans+w[x]+w[y]<<endl;
	} 
	return 0;
}
