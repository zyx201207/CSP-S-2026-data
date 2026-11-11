#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int c,d;//我不知道有啥用的：测试点编号，每个点最多线路数 
int q; //查询数
int n,m;//n个地铁线，m个地铁站 。n<=500，m<=500000 

long long w[500010];//每个地铁站固定权值
long long k[510],dp[1010][1010];//只是骗分，故dp开比较小 
vector<pair<int,int>> V[510];//V就是a数组 
int l,r;

void build_init() {//直观线路生成 ，m^2 
	for(int i = 1;i<=n;i++) {
//		cout<<"正在看第"<<i<<"条线路：\n";
		for(int j = 0;j<V[i].size();j++) {
			for(int k = j + 1;k<V[i].size();k++) {
				int u = V[i][j].first,v = V[i][k].first;
				long long w = V[i][j].second + V[i][k].second;
//				cout<<u<<"通往"<<v<<"，代价为"<<w<<"\n\n";
				dp[u][v] = min(dp[u][v],w);
				dp[v][u] = min(dp[v][u],w);
			}
		}
	}
}

void build_sec() {//次级线路生成 m^3
	for(int i = 1;i<=m;i++)
		for(int j = i + 1;j<=m;j++) {
			for(int k = 1;k<=m;k++) {
//				cout<<"正在看"<<i<<"通往"<<j<<"，中转站"<<k;
				dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]);
				dp[j][i] = min(dp[j][i],dp[j][k] + dp[k][i]);
//				cout<<"；；；dp大小为"<<dp[i][j]<<"\n\n";
			}
		}
}

void build() {
	build_init();
//	cout<<"\n===========直观生成完成！=============\n";
	build_sec();
}

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++)
		cin>>w[i];
		
	//对dp数组初始化
	for(int i = 1;i<=m;i++) 
		for(int j = 1;j<=m;j++) {
			if(i == j)
				continue;
			dp[i][j] = INF;
		}
	
	int tmpv,tmpw;
	for(int i = 1;i<=n;i++) {
		cin>>k[i];
		for(int j = 1;j<=k[i];j++) {
			cin>>tmpv>>tmpw;
			V[i].push_back({tmpv,tmpw});
		}
	}
	
	build();
	
	while(q--) {
		cin>>l>>r;
		cout<<dp[l][r] + w[l] + w[r]<<'\n';
	}
	
	return 0;
} 
