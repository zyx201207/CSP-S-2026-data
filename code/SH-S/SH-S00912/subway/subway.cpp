#include<bits/stdc++.h> 
using namespace std;
vector<int>g[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,w[10005],t[10005][1005],k,xx,yy,x,y,f[1005][1005];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>xx>>yy;
			g[i].push_back(xx);
			g[xx].push_back(i);
			t[xx][i]=yy;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		while(x!=y){
			for(int j=0;j<g[x].size();j++){
				f[x][j]=min(f[x][j],f[x][j+t[x][j]]);
			}
		}
		cout<<i<<endl;
	}
	
	return 0;
}






