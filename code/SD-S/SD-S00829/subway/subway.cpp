#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500001];
struct stru{
	int k,gd[21],t[21];
}lx[501];
int bfs(int hc,int y,int l){
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		 cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>lx[i].k ;
		for(int j=1;j<=lx[i].k ;j++){
			cin>>lx[i].gd[j]>>lx[i].t[j];
		}
	} 
	for(int i=1;i<=q;i++){
		 int x,y;
		 cin>>x>>y;
		 cout<<bfs(x,y,0);
	} 
	return 0;
}

