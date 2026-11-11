#include<bits/stdc++.h>
#define N 2000005
#define int long long 
#define inf 0x3f3f3f3f3f3f3f3fLL
using namespace std;
int c,T;
int n,d,x[N],ans;
int min_cnt,minn;
struct node{
	int to;
	int dis;
};
vector<node> G[N];
void dfs(int u,int end,int cnt){
	if(u==end){
		if(cnt==min_cnt){
			minn++;
//		cout<<"min_cnt="<<min_cnt<<" minn="<<minn<<"\n";
			return ;
		}
		else if(cnt<min_cnt){
			min_cnt=cnt;
			minn=1;
//		cout<<"min_cnt="<<min_cnt<<" minn="<<minn<<"\n";
			return ;
		}
	}
	for(auto v:G[u]){
//		cout<<"u="<<u<<" v="<<v.to<<" dis="<<v.dis<<"\n";
		dfs(v.to,end,cnt+1);
	}
} 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>T;
	while(T--){
		ans=0;
		for(int i=1;i<=n;i++){
			G[i].clear();
		}
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n>5000){
			int xx=x[2]-x[1];
			if(d<2*xx){
				cout<<"0\n";
				continue;
			}
//			cout<<"xx="<<xx<<"\n";
			int num=(x[n]-x[1])/xx+1,aaa=d/xx+2;
			cout<<num-aaa<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(x[i]-x[j])<=d){
//					cout<<"u="<<i<<" v="<<j<<"\n";
					G[i].push_back({j,abs(x[i]-x[j])});
//					G[j].push_back({i,abs(x[i]-x[j])});
				}
				else{
					break;
				}
			}
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n&&j!=i+1&&j!=i+2;j++){
				min_cnt=inf;
				minn=0;
				dfs(i,j,0);
				if(minn==2&&min_cnt!=inf){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

