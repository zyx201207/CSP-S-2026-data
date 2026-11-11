#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
const int INF=1e9;
int c,n,m,d,q,k;
ll w[N],t[N];
int a[N]; 
ll dp[N][N];
int s[5][N];
struct node{
	int v;
	ll w;
	bool operator<(const node&b)const{
		return w>b.w;
	}
};
vector<node>ve[N];
ll bfs(int x,int y){
	priority_queue<node>q;
	q.push({x,0});
	while(!q.empty()){
		node t=q.top();
		q.pop();
		if(t.v==y)return t.w;
		for(auto it:ve[t.v])q.push({it.v,it.w+t.w});
	}
	return -1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	if(c<=999){
		for(int i=1;i<=n;i++){
			cin>>k;
			for(int j=1;j<=k;j++)cin>>a[j]>>t[j];
			for(int l=1;l<=k;l++){
				for(int l1=l+1;l1<=k;l1++){
					ll pos=t[l]+t[l1];
					ve[a[l]].push_back({a[l1],pos});
					ve[a[l1]].push_back({a[l],pos});
				}
			}
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			cout<<bfs(x,y)+w[x]+w[y]<<"\n";
		}
		return 0;
	}
	
	return 0;
}
