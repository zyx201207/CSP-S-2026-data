#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
vector<int>v;
int dis[N][N];
int vis[N];
int c,n,m,d,q;
int dfs(int mb,int lc,int dq){
	if(dq==mb){
		return lc;
	}
	for(int i=0;i<n;i++){
		
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
//	if(c>=7&&c<=11){
//		spja();
//		return 0;
//	}
	for(int i=0;i<m;i++){
		int x;
		cin>>x
		v.push_back(x);
	}
	for(int i=0;i<n;i++){//xianlushu
		int ii;
		cin>>ii;//xianluzhanshu
		for(int j=0;j<ii;j++){
			int ta,tt;
			cin>>ta>>tt;
			dis[ta][i]=tt;
		}
	}
	for(int i=0;i<q;i++){
		int ans=0;
		int x,y;
		cin>>x>>y;
		ans+=v[x-1]+v[y-1];
		x--,y--;
		priority_queue<int>q;
		q.push(x);
		int tans=INT_MAX
		cout<<ans<<"\n";
	}
	return 0;
} 
