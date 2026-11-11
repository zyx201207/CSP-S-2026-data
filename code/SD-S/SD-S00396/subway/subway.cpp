#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[500010];
struct node{
	int u,val;
};
vector<node> vec[500010];
int a[500010];
int t[500010];
int xx,yx,cnt=1e18;
void dfs(int x,int fa,int sum,int yy){
	if(x==yy){
		cnt=min(cnt,sum);
		return;
	}
	for(auto it:vec[x]){
		if(it.u==fa)continue;
		dfs(it.u,x,sum+it.val,yy);
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<k;j++){
			vec[a[j]].push_back({a[j+1],t[j+1]+t[1]});
		}
	}
	while(q--){
		cin>>xx>>yx;
		dfs(xx,-1,0,yx);
		cout<<w[xx]+w[yx]+cnt<<"\n";
	}
	return 0;
} 
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
