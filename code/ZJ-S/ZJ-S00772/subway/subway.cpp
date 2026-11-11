#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;

int C,n,m,d,Q;
int w[N],k[N],dis[N];
vector<int>a[N],t[N],lu[N],tim[N];//点i在那些线路里 
//注意m是点数，n是线路数！！！ 

struct Node{
	int dis,tar;
	friend bool operator <(Node a,Node b){
		return a.dis>b.dis;
	}
};
priority_queue<Node>q;

int dij(int st,int ed){
	for(int i=1;i<=m;i++)dis[i]=1e18;
	dis[st]=0;
	q.push({0,st});
	while(q.size()){
		int x=q.top().tar, D=q.top().dis;
		q.pop();
		if(dis[x]!=D)continue;
		for(int i=0;i<lu[x].size();i++){
			int ro=lu[x][i];
			for(int j=0;j<k[ro];j++){
				int to=a[ro][j], len=t[ro][j]+tim[x][i];
				if(dis[x]+len<dis[to]){
					dis[to]=dis[x]+len;
					q.push({dis[to],to});
				}
			}
		}
	}
	return dis[ed];
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
			lu[x].push_back(i);
			tim[x].push_back(y);
		}
	}
	
	while(Q--){
		int x,y;
		cin>>x>>y;
		int ans=0;
		ans=dij(x,y);
		cout<<ans+w[x]+w[y]<<'\n'; //记得加 
	} 
	return 0;
}
