#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,d,q;
int w[500005];
int k[500005];
int a[505][50005];
int t[505][50005];
struct node{
	int id,ti;
};
vector<node> sub[50005];
int dis[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			sub[a[i][j]].push_back({i,t[i][j]});
		}
		dis[i][i]=0;
	}
	if(n>2){
	for(int li=1;li<=n;li++){
		for(int i=1;i<k[li];i++){
			for(int j=i+1;j<=k[li];j++){
				int x=a[li][i],y=a[li][j];
				for(int l=0;l<(int)sub[x].size();l++){
					for(int p=0;p<(int)sub[y].size();p++){
						node line1=sub[x][l],line2=sub[y][p];
						int u=line1.id,v=line2.id;
						dis[u][v]=min(dis[u][v],line1.ti+t[li][i]+t[li][j]+line2.ti);
					}
				}
			} 
		}
	}
	}
	else{
		for(int i=1;i<=k[1];i++){
			for(int j=1;j<=k[2];j++){
				int x=a[1][i],y=a[2][j];
				if(x==y){
					dis[1][2]=min(dis[1][2],t[1][i]+t[2][j]);
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(x>y) swap(x,y);
		int minn=0x3f3f3f3f;
		for(int i=0;i<(int)sub[x].size();i++){
			for(int j=0;j<(int)sub[y].size();j++){
				node line1=sub[x][i],line2=sub[y][j];
				minn=min(minn,dis[line1.id][line2.id]+line1.ti+line2.ti);
//				cout<<t[line1.id][x]+t[line2.id][y]<<"\n\n\n";
			}
		}
		cout<<minn+w[x]+w[y]<<'\n';
	}
	return 0;
}

