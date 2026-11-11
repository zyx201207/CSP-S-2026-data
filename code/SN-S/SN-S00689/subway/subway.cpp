#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1e3+5;
int INF = int(1e9);
int c,n,m,d,q;
int w[N];
int a[N];
int trans[205][503];
//inline void floyd() {
//	for(int mid = 1;mid<=m;mid++) {
//		for(int i=1;i<=m;i++) {
//			if(i==mid) continue;
//			for(int j=1;j<=m;j++) {
//				if(i==j||j==mid) continue;
//				int addition = 0;
//				int line1 = line[i][mid];
//				int line2 = line[j][mid];
//				if(line1!=line2) addition = trans_cost[line1][mid]+trans_cost[line2][mid]; // not same line
//				dp[i][j] = min(dp[i][mid]+dp[mid][j]+addition,dp[i][j]);
//				if(dp[i][j]<dp[i][mid]+dp[mid][j]+addition) {
//					if(line1!=0&&line2!=0) fix[i][j]=line1,fix[j][i]=line2;
//				}
//			}
//		}
//		
//		
//	}
//	
//	
//	return;
//}

struct Edge {
	int to,next,w;
} edge[2*N];
int idx=0,head[2*N];
int cnt;
inline void add(int _a,int b,int w) {
	edge[++idx].to=b;
	edge[idx].w=w;
	edge[idx].next=head[_a];
	head[_a]=idx;
	return;
}

bool vis[N];
int dis[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> qu;
void dij(int st,int ti) {
	memset(vis,0,sizeof vis);
	memset(dis,0,sizeof dis);
	dis[st]=0;
	qu.push(make_pair(0,st));
	while(!qu.empty()) {
		int x = qu.top().second;
		qu.pop();
		if(vis[x]) continue;
		vis[x]=true;
		for(int i=head[x];i;i=edge[i].next) {
			int to = edge[i].to;
			if(dis[to]>dis[x]+edge[i].w) {
				dis[to]=dis[x]+edge[i].w;
				qu.push(make_pair(dis[to],to));
			}
		}
	}
	
}

int vistim[600];

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	cnt=m*n+100;
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) {
		int k; cin>>k;
		for(int j=1;j<=k;j++) {
			int sta,t;
			cin>>sta>>trans[i][j];
			a[j]=sta;
			cnt++;
			if(j>1) {
				int M = i*200;
				add(a[j]+M,cnt,trans[i][j]);
				cout<<a[j]+M<<endl;
				add(cnt,a[j]+M,trans[i][j]);
				add(a[j-1]+M,cnt,trans[i][j-1]);
				add(cnt,a[j-1]+M,trans[i][j-1]);
			
			
			
			}
		
		}
	}
	
	
	
	if(c<=8) {
		for(int _=1;_<=q;_++) {
			int i,j; cin>>i>>j;
			dij(i,_);
			cout<<dis[j]+w[i]+w[j]<<endl;;
			
		}
		
	}
	
	return 0;
}
