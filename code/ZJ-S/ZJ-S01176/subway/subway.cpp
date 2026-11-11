#include <bits/stdc++.h>
using namespace std;

struct Node{
	int v,t;
};

int c,n,m,d,Q;
int w[2000005];
vector<vector<int>> a(2000005);//the lines that this station could reach;
vector<vector<int>> edge(501);//the stations that this line could reach;
int dp[200005][501];//the time that stations go to eack line should spend;

vector<vector<Node>> MAP(501);
int dp2[501][501];//the smallest distance between each line;
int ans;

int flag[501];//used to check if this station is comed;

void creat(int u){
	for(int i=0;i<edge[u].size();i++){
		int point=edge[u][i];
		for(int j=0;j<a[point].size();j++){
			int v=a[point][j];
			if(u==v)continue;
			if(dp2[u][v]==0){
				dp2[u][v]=dp[point][u]+dp[point][v];
				dp2[v][u]=dp2[u][v];
			}
			else{
				dp2[u][v]=min(dp2[u][v],dp[point][u]+dp[point][v]);
				dp2[v][u]=dp2[u][v];
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin >> c >> n >> m >> d >> Q;
	for(int i=1;i<=m;i++)cin >> w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		while(k--){
			int a_,t_;
			cin >> a_ >> t_;
			a[a_].push_back(i);
			edge[i].push_back(a_);

			dp[a_][i]=t_;
		}
	}
	//cout << dp[2][1] <<endl <<endl;

	for(int i=1;i<=n;i++){
		creat(i);
		
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(dp[i][j]!=0){
				MAP[i].push_back({j,dp2[i][j]});
				MAP[j].push_back({i,dp2[i][j]});
			}
		}
	}
	
	for(int i=1;i<=n;i++){//sove the smallest distance between each lines;
		queue<Node> q;
		for(int j=1;j<=n;j++)flag[j]=0;
//		q.push({1,0}); //used to test;
//		flag[1]=1; //used to test;
		q.push({i,0});
		flag[i]=1;
		while(!q.empty()){
			int v=q.front().v,t=q.front().t;
			q.pop();
			if(flag[v])continue;
			flag[v]=1;
//			if(t>dp2[1][v])continue; //used to test;
			if(t>dp2[i][v])continue;
//			else dp2[1][v]=t; //used to test;
			else dp2[i][v]=t;
			for(int j=0;j<MAP[v].size();j++){
//				if(flag[MAP[v][j].v] || t+MAP[v][j].t>=dp2[1][MAP[v][j].v])continue; //used to test
				if(flag[MAP[v][j].v] || t+MAP[v][j].t>=dp2[i][MAP[v][j].v])continue;
				q.push({MAP[v][j].v,MAP[v][t].t+t});
			}
		}
	}

	//cout << dp[2][1] <<endl <<endl;

	for(int i=0;i<Q;i++){
		int x,y;
		cin >> x >> y;
		ans=1e9+7;
		for(int i:a[x]){
			for(int j:a[y]){
				ans=min(ans,dp2[i][j]+w[x]+w[y]+dp[x][i]+dp[y][j]);	
			}
		}
		cout << ans << endl;
	}
}