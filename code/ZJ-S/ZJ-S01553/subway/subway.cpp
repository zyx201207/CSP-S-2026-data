#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
int c,n,m,D,q;
const int N=505,M=5005,inf=1e9+7;
int w[M],k[N],d[M][M];
int t[M][N];
vector<int>g[M][M];
void floyd(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(d[i][j]==0)d[i][j]=inf;
		}
		for(int j=1;j<=n;j++){
			if(t[i][j]==0)t[i][j]=inf;
		}
	}
	int ch1=0,ch2=0,ip1,ip2,change=inf;
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){

				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int x,y;
	int Q;
	cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int lst=0,lsy=0;
		vector<int>vvv;
		for(int j=1;j<=k[i];j++){
			cin>>x>>y;
			vvv.push_back(x);
			if(lst!=0){
				g[lst][x].push_back(i);
				g[x][lst].push_back(i);
				d[x][lst]=y+lsy;
				d[lst][x]=y+lsy;
			}
			t[x][i]=y;
			lst=x,lsy=y;
		}
		for(int l=0;l<vvv.size();l++){
			for(int r=0;r<vvv.size();r++){
				if(vvv[l]!=vvv[r]){
					d[vvv[r]][vvv[l]]=d[vvv[l]][vvv[r]]=t[vvv[l]][i]+t[vvv[r]][i];
				}
			}
		}
	}
	Q=q;
	floyd();
	while(q--){
		cin>>x>>y;
//		cout<<Q-q<<' ';
		cout<<d[x][y]+w[x]+w[y]<<endl;
	}
//	cout<<d[1][5]<<' '<<d[5][6];
	return 0;
}
