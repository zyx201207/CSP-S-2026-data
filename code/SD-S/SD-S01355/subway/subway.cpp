#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#include<stack>
#include<cstring>
#include<vector>
using namespace std;
const int N=5e5+10,M=510;
const long long INF=1e14;
struct node{
	long long num,val;
};
long long n,m,w[N],c,d,q,k[M],dis[M][M],vis[N];
vector<node> v[N];
void Floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=INF;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			long long a,t;
			cin>>a>>t;
			v[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		int len=v[i].size();
		for(int j=0;j<v[i].size();j++){
			for(int w1=j+1;w1<v[i].size();w1++){
				long long num1=v[i][j].num,num2=v[i][w1].num,val1=v[i][j].val,val2=v[i][w1].val;
				dis[num1][num2]=min(dis[num1][num2],val1+val2);
				dis[num2][num1]=dis[num1][num2];
			}
		}
	}
	Floyd();
	for(int i=1;i<=q;i++){
		int u1,v1;
		cin>>u1>>v1;
		long long ans=INF;
		for(auto j:v[u1]){
			for(auto w1:v[v1]){
				ans=min(ans,j.val+w1.val+dis[j.num][w1.num]);
			}
		}
		cout<<ans+w[u1]+w[v1]<<'\n';
	}
	return 0;
} 
