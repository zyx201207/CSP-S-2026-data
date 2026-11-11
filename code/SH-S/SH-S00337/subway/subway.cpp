#include<bits/stdc++.h>
#define final one
using namespace std;

int n,m,c,d,q,w[100001],k,u,v,dis[1000],now,t,mp[501][501],va,line[1001][1001],tim[1001][1001],stop[1001][1001],start,mi=0x3f3f3f,mini;



int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>now>>va;
			stop[now][stop[now][0]+1]=k;
			stop[now][0]++;
			
			tim[now][tim[now][0]+1]=va;
			tim[now][0]++;
		}
	}
	for(int i=1;i<=m;i++){
		if(stop[i][0]!=1){
			for(int j=1;j<=stop[i][0];j++){
				for(int k=j+1;k<=stop[i][0];k++){
					mp[stop[i][j]][stop[i][k]]=tim[now][j]+tim[now][k];
					mp[stop[i][k]][stop[i][j]]=tim[now][j]+tim[now][k];
					
				}
			}
		}
	}
	for(int i=0;i<q;i++){
		cin>>u>>v;
		for(int j=1;j<=n;j++){
			dis[i]=0x3f3f3f;
		}
		mini=0x3f3f3f;
		for(int j=1;j<=stop[u][0];j++){
			start=stop[u][j];
			dis[start]=w[u];
			
			for(int k1=1;k1<=n;k1++){
				for(int l1=1;l1<=n;l1++){
					dis[l1]=min(dis[l1],dis[k1]+mp[k1][l1]);
				}
			}
			for(int k1=1;k1<=stop[v][0];k1++){
				if(dis[k1]<mi){
					mi=dis[k1];
				}
			}
			mini=min(mini,mi+w[v]+w[u]+tim[u][start]);
		}
		
		cout<<mini<<endl;
	}
	return 0;
}
