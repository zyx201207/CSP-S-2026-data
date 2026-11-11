#include <iostream>
#include <vector>
#include <queue> 

using namespace std;
using ll = long long;

const int N = 500005;
int c,n,m,d,q;
vector<vector<int>> path;
ll dist[N];
int sum;

struct subway_station{
	int w; 
	vector<int> sta(1000); 
};

struct station{
	int sbid; 
	int stid; 
	int dis;
	int pre;
}; 


station sta[N];
subway_station sbt[N];
pair<ll,ll> plan[n];
pair<ll,ll> f[N][N];


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	path.reserve(n+5);
	
	for(int i=1;i<=m;i++){
		int w;
		cin>>w;
		sbt[i].w=w;
	}
	
	for(int i=1;i<=n;i++){
		f[i][i]={0,0};
	}
	
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int pre = -1;
		for(int j=1;j<=k;j++){
			int s,t;
			cin>>s>>t;
			sum++;
			path[i].push_back(s);
			sta[sum].sbid = s;
			sta[sum].stid = i;
			if(pre!=-1){
			}
			
		}
	} 
	
	for(int i=1;i<=q;i++){
		int s,t;
		cin>>s>>t;
	}
		
	return 0;
}
