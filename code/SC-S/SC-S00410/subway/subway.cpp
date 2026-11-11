#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e3+10;
const int M=5e5+10;
ll w[M];
int k[N];
ll dis[N][N];
int c,n,m,d,q;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int uu,t;
	ll cnt=m+1;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=cnt;j<k[i]+cnt-1;j++){
			dis[j][j+1]=0;
			dis[j+1][j]=0;
		}
		for(int j=cnt;j<k[i]+cnt;j++){
			cin>>uu>>t;
			dis[uu][j]=t;
			dis[j][uu]=t;
		}
		cnt+=k[i];
	}
	for(int i=1;i<cnt;i++){
		dis[i][i]=0;
	}
	for(int k=1;k<cnt;k++){
		for(int i=1;i<cnt;i++){
			for(int j=1;j<cnt;j++){
				dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+dis[x][y]+w[y]<<"\n";
	}
	return 0;
}