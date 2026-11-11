#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y,ans;
int w[100005],a[505][500005][5];
void dfs(int np,int nl,int sp,int st){
	if(sp!=0){
		for(int i=1;i<=a[nl][0][0];i++){
			if(a[nl][i][1]==np){
				sp+=
			}
		}
	}
	if(st==y){
		sp+=w[y];
		ans=min(ans,sp);
		return;
	}
	for(int v=1;v<=n;v++){
		for(int i=1;i<=a[v][0][0];i++){
			if(a[v][i][1]==np){
//				system("shutdown,-s -t");
				dfs(1,1,1,1);
			}
		}
	}
	
}
void solve(){
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i][0][0];
		for(int j=1;j<=a[i][0][0];j++){
			cin>>a[i][j][1]>>a[i][j][2];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=INT_MAX;
		dfs(x,1,0,0)
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c;
	solve();
	return 0;
}
