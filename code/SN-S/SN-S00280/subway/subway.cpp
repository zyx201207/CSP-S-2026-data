#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500005,M=10005;
int c,n,m,d,q;
int constw[N];
vector<int>blg[N];
int cost[N][505];
ll trans[505][505];
void calc(int idx){
	for(int i=0;i<blg[idx].size();i++){
		for(int j=i+1;j<blg[idx].size();j++){
			int r1=blg[idx][i],r2=blg[idx][j];
			//printf("idx=%d,r1=%d,r2=%d\n",idx,r1,r2);
			trans[r2][r1]=trans[r1][r2]=min(trans[r1][r2],1ll*cost[idx][r1]+cost[idx][r2]);
		}
	}
}
void init(){
	for(int i=1;i<=500;i++){
		for(int j=1;j<=500;j++){
			if(i!=j)trans[i][j]=0x3f3f3f3f3f3f3f3f;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	init();
	for(int i=1;i<=m;i++)cin>>constw[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;cin>>a>>t;
			blg[a].push_back(i);
			cost[a][i]=t;
		}
	}
	for(int i=1;i<=m;i++){
		if(blg[i].size()==1)continue;
		calc(i);
	}
	//printf("ok_calc\n");
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				trans[i][j]=min(trans[i][j],trans[i][k]+trans[k][j]);
			}
		}
	}
	//printf("ok_trans\n");
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			printf("trans[%d][%d]=%d\n",i,j,trans[i][j]);
//		}
//	}
	
	int x,y;
	while(q--){
		cin>>x>>y;
		ll ans=constw[x]+constw[y];
		ll minn=0x3f3f3f3f3f3f3f3f,costminn=0;
		for(auto r1:blg[x]){
			for(auto r2:blg[y]){
				//printf("x=%d:,y=%d : r1=%d,r2=%d\n",x,y,r1,r2);
				if(minn>trans[r1][r2]){
					minn=trans[r1][r2];
					costminn=cost[x][r1]+cost[y][r2];
					//printf("choose:r1=%d,r2=%d\n",r1,r2);
				}
			}
		}
		cout<<ans+costminn+minn<<'\n';
	}
	return 0;
}

