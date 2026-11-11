#include<bits/stdc++.h>
using namespace std;
int a[500010][505];
int ww[500010];
int ans=-1;
void dfs(int x,int y,int cnt){
	if(a[y][x]!=0){
		ans=max(ans,cnt);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>ww[i];
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int n,m;
			cin>>n>>m;
			a[n][i]=m;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		dfs(x,y,0);
	}
	return 0;
} 
