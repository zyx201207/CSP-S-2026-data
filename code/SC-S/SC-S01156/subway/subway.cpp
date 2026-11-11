#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e2+10,M=5e5+10;
int c,n,m,d,q;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
int w[N],a[M][N],t[M][N];
int k[N];
int adj[N];
vector<pair<int,int>> grid[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			cnt+=a[i][j];
		}	
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y; 
		cout<<cnt<<endl;
	}
	return 0;
}
