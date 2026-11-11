#include<bits/stdc++.h>//nm-->nn is waiting----complete
#define pll pair<long long int,long long int>
#define ll long long int
using namespace std;
struct node{
	ll l;
	ll p;
};
ll re[1000][1000],dist[1000];
int w[510000];
ll c,n,m,d,Q,st,ed,len[1000][1000];
vector<node> v[510000],v1[1000];
priority_queue<pll,vector<pll>,greater<pll> > q;
void dijk(int x){
	memset(dist,0x3f,sizeof dist);
	dist[x]=0;
	q.push({0,x});
	while(!q.empty()){
		pll t=q.top();
		q.pop();
		for(node ne:v1[t.second]){
			if(dist[ne.p]>t.first+ne.l){
				dist[ne.p]=t.first+ne.l;
				q.push({t.first+ne.l,ne.p});
			}
		}
	}
	
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int a,k,t;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			v[i].push_back({t,a+1000});
			v[a+1000].push_back({t,i});
		}
	}
	memset(len,0x3f,sizeof len);
	for(int i=1;i<=n;i++){
		for(node x:v[i]){
			for(node y:v[x.p]){
				if(y.p!=i){
					len[i][y.p]=min(len[i][y.p],x.l+y.l);
					len[y.p][i]=len[i][y.p];
				}
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j&&len[i][j]!=0x3f3f3f3f3f3f3f3f){
				v1[i].push_back({len[i][j],j});
				v1[j].push_back({len[i][j],i});
			}
		}
	}
	memset(re,0x3f,sizeof re); 
	for(int i=1;i<=n;i++){
		dijk(i);
		for(int j=1;j<=n;j++){
			re[i][j]=dist[j];
		}
	}
	while(Q--){
		ll mind=0x3f3f3f3f3f3f3f3f;
		cin>>st>>ed;
		for(node x:v[st+1000]){
			for(node y:v[ed+1000]){
				mind=min(mind,re[x.p][y.p]+x.l+y.l);
			}
		}
		cout<<mind+w[st]+w[ed]<<"\n";
	}
	return 0;
}
/*

12	49	D:\ÏÂ·¢ÏÂÎç\SH-S01007zhanghaorui\subway\subway.cpp	[Error] conflicting declaration 'std::priority_queue<std::pair<int, std::pair<bool, int> >, std::vector<std::pair<int, std::pair<bool, int> > >, std::greater<std::pair<int, std::pair<bool, int> > > > q'
*/
