/*
ュュュュュュュュュュュュュュュュュュュュュュュュュュュュュュュュュュュュュュュュュュュュュュュュュュュュ
*/
#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,x;
};
int c,n=0,m=0,d=0,q=0,w[500005],dis[1005][1005];
vector<node> v[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
	 for(int j=1;j<=m;j++){
	  dis[i][j]=1e9;
}
}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			node x;
			cin>>x.a>>x.x;
			v[i].push_back(x);
		}
		for(auto x:v[i]){
			for(auto y:v[i]){
				dis[x.a][y.a]=min(dis[x.a][y.a],x.x+y.x);
			}
		}
	}
	for(int i=1;i<=m;i++) dis[i][i]=0;
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i==j||j==k||i==k) continue;
				if(dis[i][k]!=1e9&&dis[k][j]!=1e9){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}                                      
			}
		}
	}
	
	for(int i=1;i<=q;i++){
		int s,t;
		cin>>s>>t;
		cout<<dis[s][t]+w[s]+w[t]<<"\n";
	}
	return 0;
}
