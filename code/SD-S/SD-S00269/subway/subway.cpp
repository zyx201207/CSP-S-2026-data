#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=505,D=25;
const int M=5e5+5; 
int a[N][D];
int w[N];
set<int> st[N];
vector<pii> v[M];
int QWER[M];
int c,n,m,d,q;
namespace pts78{
	int ans=1e18,minn=1e18;
	int vis[M];
	void dfs(int now,int end,int sum,int line){
//		cout<<"now in "<<now<<"\n";
		if(now==end){
			sum+=w[now];
			sum+=a[now][line];
//			cerr<<sum<<endl;
			minn=min(minn,sum);
		}
		for(auto i:v[now]){
			int nxt=i.first,tlin=i.second;
			if(vis[nxt]) continue;
			if(line!=tlin){
				vis[now]=1;
				int cost=0;
				if(line!=0){
					cost+=a[now][line];
				}
				cost+=a[now][tlin];
				dfs(nxt,end,sum+cost,tlin);
				vis[now]=0;
			}
			else{
				vis[now]=1;
				dfs(nxt,end,sum,line);
				vis[now]=0;
			}
		}
	}
	void solve(){
		while(q--){
			int beg,end;
			cin>>beg>>end;  
			dfs(beg,end,w[beg],0);
			cout<<minn<<endl;
			minn=1e18;
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int y;
			cin>>QWER[j]>>y;
			a[QWER[j]][i]=y;
			if(j!=1){
				v[QWER[j-1]].push_back({QWER[j],i});
				v[QWER[j]].push_back({QWER[j-1],i});
			}
		} 
	}
	pts78::solve();
	return 0;
} 
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


1 4 2 5 5 100
2 6 3 1 7 2
3 2 5 100 4 6 6 7



0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
