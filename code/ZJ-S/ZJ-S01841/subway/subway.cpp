#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],k,a[510][5010],t[510][5010],x,y,mi;
void dfs(int x,int y,int time){
	if(x==y){
		
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		cin>>x>>y;
		dfs(x,y,0);
		cout<<mi;
	}
	return 0;
}