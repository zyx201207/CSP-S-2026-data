#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q; 
int w[200010];
struct node{
	int a,t;
};
node s[510][5010];
long long dis[5010][5010];
long long sum;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=5009;i++){
		for(int j=1;j<=5009;j++){
			dis[i][j]=1e18-10;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>s[i][j].a>>s[i][j].t;
		}
		for(int j=1;j<=k;j++){
			for(int p=j+1;p<=k;p++){
				dis[s[i][j].a][s[i][p].a]=s[i][j].t+s[i][p].t;
				dis[s[i][p].a][s[i][j].a]=dis[s[i][j].a][s[i][p].a];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j) dis[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int p=1;p<=m;p++){
				dis[i][j]=min(dis[i][j],dis[i][p]+dis[p][j]);
				dis[j][i]=dis[i][j];
			}
		}
	}
	
	while(q--){
		int x1,y1;
		cin>>x1>>y1;
		long long cost=0;
		cost+=w[x1];
		cost+=w[y1];
		cost+=dis[x1][y1];
		cout<<cost<<endl;
	}
	return 0;
}
