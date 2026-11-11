//汤佳忆 西安辅轮中学 SN-S00432 
#include<bits/stdc++.h>
using namespace std;
const int  M=5e5+5;
int c,n,m,d,q;
int w[M];
struct node{
	int id,qx;	
}k[502][5000];
vector<int> f;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){cin>>w[i];}
	for(int i=1;i<=n;++i){
		int x;cin>>x;
		for(int j=1;j<=x;++j){cin>>k[i][j].id>>k[i][j].qx;}
	}
	for(int i=1;i<=q;++i){
		int u,v;cin>>u>>v;
		
	}
	return 0;
}
