#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int INF=1e18;

struct Xian{
	int z,t;
};
int c,n,m,d,q;
int w[500005];
int ds[502][502];
vector<Xian> st[500002];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) cin>>w[i];
	for (int i=0;i<n;i++){
		int k; cin>>k;
		for (int j=0;j<k;j++){
			int ai,ti; cin>>ai>>ti;

			st[ai].push_back({i,ti});
		}
	}
	//初始化d数组
	
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			ds[i][j]=INF;
		}
	} 
	for (int i=0;i<m;i++){
		for (int j=0;j<st[i].size();j++){
			for (int x=j+1;x<st[i].size();x++){
				int z1=st[i][j].z,t1=st[i][j].t;
				int z2=st[i][x].z,t2=st[i][j].t;
				ds[z1][z2]=t1+t2;
				ds[z2][z1]=t1+t2;
			}
		}
	}
	
	for (int i=0;i<n;i++){//枚举起线路 
		for (int j=0;j<n;j++){//枚举终线路 
			for (int x=0;x<n;x++){//枚举中转线路 
				ds[i][j]=min(ds[i][j],ds[i][x]+w[x]+ds[x][j]);
			}
		}
	} 
	
	while (q--){
		int x,y; cin>>x>>y;
		int ans=INF;
		for(int i=0;i<st[x].size();i++){
			int u=st[x][i].z;
			for (int j=0;j<st[y].size();j++){
				int v=st[y][j].z;
				ans=min(ans,ds[u][v]);
			}
		}
		cout<<ans<<endl;
		cout<<w[x]+w[y]+ans<<endl;
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
*/
