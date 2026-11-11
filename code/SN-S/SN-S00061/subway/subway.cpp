#include<bits/stdc++.h>
using namespace std;
int t[505][405],w[405],h[505][405];	
int c,n,m,d,q,x,qd,zd;
int tim=0;
struct node{
	int nm;
	int id;
}aa[505];
int dfs(int y,int id){
	tim+=t[y][id];
	if(y==zd) return tim;
	for(int i=1;i<=aa.size();i++){
		dfs(aa[i].nm,aa[i].id);
		
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>h[i][j]>>t[i][j];
		} 
	} 
	if(n>=51){
		for(int i=1;i<=n;i++){
			for(int j=2;j<=x;j++){
				aa[h[i][j-1]].nm=h[i][j];
				aa.id=i;
			} 
		} 
		for(int 
	}
	for(int i=1;i<=q;i++){
		cin>>qd>>zd;
	}
	return 0;
} 
