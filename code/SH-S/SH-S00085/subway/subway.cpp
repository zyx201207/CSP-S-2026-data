#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int c,n,m,d,q;
const int N=505,M=5e5+5;
long long w[M];
vector<pair<int,long long> > r[M];
long long dis[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	//cout<<"end1"<<endl;
	//cout<<n<<endl;
	for(int i=1;i<=n;i++){
		int k=0;
		cin>>k;
		for(int j=1;j<=k;j++){
			long long a=0,t=0;
			cin>>a>>t;
			r[a].push_back({i,t});
		}
	}
	//cout<<"end2"<<endl;
	//cout<<n<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<r[i].size();j++){
			for(int k=0;k<j;k++){
				int a=r[i][j].first,b=r[i][k].first;
				dis[a][b]=min(dis[a][b],r[i][j].second+r[i][k].second);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			for(int k=1;k<=n;k++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				dis[j][i]=dis[i][j];
			}
		}
	}
//	cout<<111<<" "<<n<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<i<<":"<<endl;
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<222<<endl;
	for(int i=1;i<=q;i++){
		int x=0,y=0;
		cin>>x>>y;
		long long ans=1e18;
		for(int j=0;j<r[x].size();j++){
			for(int k=0;k<r[y].size();k++){
				int a=r[x][j].first,b=r[y][k].first;
				ans=min(ans,r[x][j].second+r[y][k].second+dis[a][b]);
			}
		}
		ans+=(w[x]+w[y]);
		cout<<ans<<"\n"; 
	}
	return 0;
} 
