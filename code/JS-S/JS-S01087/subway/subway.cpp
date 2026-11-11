#include<bits/stdc++.h>
using namespace std;
#define TESTING
//#define HAND_PATH

void FREOPEN(const string& s){
    if(!freopen((s+".in").c_str(),"r",stdin)){
        cerr<<"Can not open file:"<<s<<".in\n";
        return;
    }
    if(!freopen((s+".out").c_str(),"w",stdout)){
        cerr<<"Can not open file:"<<s<<".out\n";
        return;
    }
}
namespace{
	
using ll=long long;
constexpr int N=500005,M=505;;
ll v[N];
vector<pair<int,ll>> e[M];
vector<pair<int,ll>> jing[N];
int Case,m,n,d,Q;
constexpr int PASTN=1005;
ll dp[PASTN][PASTN];
void solve_floyd(){
	for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=0x3f3f3f3f3f3f3f3f;
        }
        dp[i][i]=0;
        for(const auto& ind:jing[i]){
            for(const auto& o:e[ind.first]){
				if(o.first<0||o.first>n)abort();
                dp[i][o.first]=min(dp[i][o.first],ind.second+o.second);
            }
        }
	}
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    while(Q--){
        int x,y;
        cin>>x>>y;
        cout<<v[x]+v[y]+dp[x][y]<<"\n";
    }
}
int dis[M];
struct cmp{
	bool operator()(int x,int y){
		return dis[x]>dis[y];
	}
};
void solve_t(int t){
	vector<vector<int>> e(m+2);
	for(int i=1;i<=n;i++){
		for(const auto& x:jing[i]){
			for(const auto& y:jing[i]){
				if(x.first!=y.first){
					e[x.first].push_back(y.first);
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		sort(e[i].begin(),e[i].end());
		e[i].resize(unique(e[i].begin(),e[i].end())-e[i].begin());
	}
	
	while(Q--){
		int x,y;
		cin>>x>>y;
		priority_queue<int,vector<int>,cmp> q;
		memset(dis,0x3f,sizeof(dis));
		for(const auto& p:jing[x]){
			q.push(p.first);
			dis[p.first]=t;
		}
		vector<int> vis(m+5,0);
		while(!q.empty()){
			int x=q.top();q.pop();
			if(vis[x])continue;
			vis[x]=1;
			for(int y:e[x]){
				if(dis[y]>dis[x]+2){
					dis[y]=dis[x]+2;
					q.push(y);
				}
			}
		}
		int mn=INT_MAX;
		for(const auto& p:jing[y]){
			mn=min(mn,dis[p.first]);
		}
		cout<<v[x]+v[y]+mn*t+t<<"\n";
	}
}
/*
0 2 4 1 1
0 0 0 0
3 1 1 2 1 3 1
3 1 1 3 1 4 1

*/
void solve(){
    cin>>Case>>m>>n>>d>>Q;
    ll all_t=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=m;i++){
        int k;
        cin>>k;
        e[i].resize(k);
        for(int j=0;j<k;j++){
            cin>>e[i][j].first>>e[i][j].second;
            if(!all_t){
				all_t=e[i][j].second;
			}else if(all_t!=e[i][j].second)all_t=-1;
            jing[e[i][j].first].push_back({i,e[i][j].second});
        }
        sort(e[i].begin(),e[i].end());
    }
	if(all_t!=-1)solve_t(all_t);
    if(n<=1000)solve_floyd();
} 
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
#if !defined(NON_JUDGE) || defined(TESTING)
    FREOPEN("subway");
#elif defined(HAND_PATH)
    string path;
    cin>>path;
    FREOPEN(path);
#endif
    solve();
    return 0;
}
