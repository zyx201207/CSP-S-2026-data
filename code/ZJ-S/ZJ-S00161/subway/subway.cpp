#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p,ans=0,tt1=1e9;
int st,ed;
int w[500007];
struct node{
	int su,t;
};
vector<node>g[500007];
bool check1(){
	for(int i=1;i<=g[st].size();i++)
		for(int j=1;j<=g[ed].size();j++){
			if(g[st][i].su==g[ed][j].su){
				tt1=min(tt1,g[st][i].su+g[ed][j].su);
				return 1;
			}
		}
		return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			g[x].push_back({i,y});
		}
	}
	for(int i=1;i<=p;i++){
		
		cin>>st>>ed;
		if(check1()){
			cout<<w[st]+w[ed]+tt1<<"\n";
		}
		else if(n==2){
		
			for(int i=1;i<=n;i++){
				if(g[i].size()==2){
					cout<<g[i][1].t+g[i][2].t+w[st]+w[st]+g[st][1].t+g[ed][2].t;
				}
			}
		}
	}
	
	return 0;
}
