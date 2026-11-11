#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int>pll;	
int c,n,m,d,q;//n 是线路条数 m是点数  d是一个点最多会被多少路线经过  q是询问次数 
int w[500010];
vector<pll>pos[500010]; //每个点被那些路线穿过 费用是什么
int f[510][510];//最短路 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	memset(f,0x3f,sizeof f);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		f[i][i]=0;
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,cost;
			cin>>u>>cost;
			pos[u].push_back({i,cost});
		}
	}
	for(int i=1;i<=m;++i){
		for(int a=0;a<pos[i].size();++a){
			for(int b=a+1;b<pos[i].size();++b){
				pll l=pos[i][a],r=pos[i][b];
				int u1=l.first,u2=r.first,cost=l.second+r.second;
				f[u1][u2]=min(f[u1][u2],cost);
				f[u2][u1]=min(f[u2][u1],cost);
			//	cout<<u1<<' '<<u2<<' '<<cost<<"!!!!!!!!!!!!!!\n";
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			for(int k=1;k<=n;++k){
				if(f[i][k]>=0x3f3f3f3f3f3f3f3f||f[k][j]>=0x3f3f3f3f3f3f3f3f)continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				f[j][i]=min(f[j][i],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		int ans=1e18; 
		for(auto i:pos[l]){
			for(auto j:pos[r]){
			 	int u1=i.first,c1=i.second,u2=j.first,c2=j.second;
			 	if(f[u1][u2]>=0x3f3f3f3f3f3f3f3f)continue;
			 	ans=min(ans,f[u1][u2]+c1+c2+w[l]+w[r]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3



*/
