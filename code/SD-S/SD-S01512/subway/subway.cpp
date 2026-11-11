#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxm=5e5+5,maxn=505;
int w[maxm],k[maxn],d[maxn];
int c,n,m,d11,q;
vector<int> a[maxn],t[maxn];
vector<pair<int,int> > ve[maxn];
void dij(int s){
	for(int i=1;i<=n;i++)d[i]=1e18;
	d[s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> > >pq;
	pq.push({0,s});//存的是在s点的站厅的最短距离 
	while(!pq.empty()){
		auto x=pq.top();
		pq.pop();
		if(x.first>d[x.second])continue;
		for(auto y:ve[x.second]){
			if(d[x.second]+x.first<d[y.second]){
				d[y.second]=d[x.second]+x.first;
				pq.push({d[y.second],y.second});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d11>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int l,ll;cin>>l>>ll;
			a[i].push_back(l),t[i].push_back(ll);
		}
		if(k[i]>2)f=1;
	}
	for(int i=1;i<=n;i++){
		if(k[i]==1)continue;
		ve[a[i-1][0]].push_back({t[i-1][a[i-1][0]]+t[i-1][a[i-1][1]],a[i-1][1]});
	} 
	while(q--){
		int x,y;cin>>x>>y;
		dij(x);
		cout<<w[x]+w[y]+d[y]<<"\n";
	}
	return 0;
}
