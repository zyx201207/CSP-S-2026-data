#include<bits/stdc++.h>
using namespace std;
int c,t,g[10000][10000];
int spfa(int gs,int rs,int n){
	int dis[50000],v[50000]={0};
	queue<int> qe;
	memset(dis,0x3f,sizeof(dis));
	dis[gs]=0;

	qe.push(gs);
	while(!qe.empty()){
		int ma=qe.front();
		
		v[ma]=0;
		qe.pop();
		for(int i=1;i<=n;i++){
			if(g[ma][i]!=0){
				if(dis[i]>dis[ma]+g[ma][i]){
					
					dis[i]=dis[ma]+g[ma][i];
					if(v[i]==0){
						qe.push(i);
						v[i]=1;
					}
				}
			}
		}
	    
	}
	return dis[rs];
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
cin>>c>>t;
while(t>0){
	t--;
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			g[i][j]=0;
		}
	}
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		g[x][y]=1;
		g[y][x]=1;
	}
	cout<<n%2<<'\n';
}
	return 0;
} 