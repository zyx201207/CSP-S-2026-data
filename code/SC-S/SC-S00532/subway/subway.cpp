#include<bits/stdc++.h>
using namespace std;
const int N=500000+100;
int w[N],tu[500+10][500+10],dis[500+10][500+10],rz[N][500+10];
bool flag[500+10]={0};
struct node{
	int k,t;
};
vector<node>zt[N];
vector<node>q[500+10];
void sp(int x){
	if(flag[x]==1)return;
	queue<int>spfa;
	while(!spfa.empty())spfa.pop();
	spfa.push(x);
	while(!spfa.empty()){
		int u=spfa.front();
		spfa.pop();
		int l=q[u].size();
		for(int i=0;i<l;i++){
			node r=q[u][i];
			if(dis[x][r.k]>dis[x][u]+r.t){
				dis[x][r.k]=dis[x][u]+r.t;
				spfa.push(r.k);
			}
		}
	}
	flag[x]=1;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(tu,0x3f,sizeof(tu));
	int c,n,m,d,r;
	cin>>c>>n>>m>>d>>r;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
//		cin>>k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a,t;
//			cin>>a>>t;
			scanf("%d%d",&a,&t);
			rz[a][i]=t;
			zt[a].push_back({i,t});
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=0;j<zt[i].size();j++){
//			cout<<i<<" "<<zt[i][j].k<<" "<<zt[i][j].t<<"\n";
//		}
//	}
	for(int i=1;i<=m;i++){
		int l=zt[i].size();
		for(int j=0;j<l-1;j++){
			for(int k=j+1;k<l;k++){
				tu[zt[i][j].k][zt[i][k].k]=
				tu[zt[i][k].k][zt[i][j].k]=
				min(tu[zt[i][j].k][zt[i][k].k],
					min(tu[zt[i][k].k][zt[i][j].k],
						zt[i][j].t+zt[i][k].t));
//				cout<<tu[zt[i][j].k][zt[i][k].k]<<"\n";
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j && tu[i][j]){
				q[i].push_back({j,tu[i][j]});
//				cout<<i<<" "<<j<<" "<<tu[i][j]<<"\n";
			}
		}
	}
	memset(dis,0x3f,sizeof(dis));
	while(r--){
		int x,y,ans=0x3f3f3f3f;
//		cin>>x>>y;
		scanf("%d%d",&x,&y);
		for(int i=0;i<zt[x].size();i++){
			dis[zt[x][i].k][zt[x][i].k]=0;
			sp(zt[x][i].k);
			for(int j=0;j<zt[y].size();j++){
				ans=min(ans,dis[zt[x][i].k][zt[y][j].k]+rz[y][zt[y][j].k]+rz[x][zt[x][i].k]);
			}
		}
//		cout<<ans+w[x]+w[y]<<"\n";
		printf("%d\n",ans+w[x]+w[y]);
	}
	return 0;
}