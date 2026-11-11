#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N=5005;

struct Node{
	int u,dep;
};

int n,d;

int a[N],dis[N][N],cnt[N][N];
vector<int>vec[N];

void bfs(int x){
	queue<Node>q;
	q.push({x,0});
	while(!q.empty()){
		int u=q.front().u;
		int dep=q.front().dep;
		q.pop();
		for(auto v:vec[u]){
			dis[x][v]=min(dep+1,dis[x][v]);
			q.push({v,dep+1});
		}
	}
	
}

void bfs2(int x){
	queue<Node>q;
	q.push({x,0});
	while(!q.empty()){
		int u=q.front().u;
		int dep=q.front().dep;
		q.pop();
		for(auto v:vec[u]){
			if(dep+1==dis[x][v]) cnt[x][v]++;
			q.push({v,dep+1});
		}
	}
}

signed main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=i-1;j>=1;j--){
				if(a[i]-a[j]<=d){
					vec[j].push_back(i);
				}else{
					break;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int inf=INT_MAX;
			memset(dis,inf,sizeof dis);
			memset(cnt,0,sizeof cnt);
			bfs(i);
			bfs2(i);
			
			for(int j=1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(cnt[j][k]==2) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
