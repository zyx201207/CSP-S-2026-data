#include<bits/stdc++.h>
using namespace std;
typedef long long ll;typedef unsigned long long ull;typedef pair<ull,ull>pii;
const int N=5e5+10;
int c,n,m,d,q;
ull w[N];
vector<pair<ull,ull> >g[N];
ull lines[N];

bitset<N>vis;
ull anss[N];
#define endl '\n'
struct ask{
	int x,y;
	int idx;
	ull ans=0;
};
bool cpp(ask &a,ask& b){
	if(a.x<b.x)return 1;
	return 0;
}
bool cpp2(ask &a,ask &b){
	if(a.idx<b.idx)return 1;
	return 0;
}

ask ass[N];
void djstl(ull st){
	vis.reset();//all0
	memset(anss,sizeof anss,0x3f3f);
//	for(int i=0;i<=m+n;i++){
//		anss[i]=LONG_LONG_MAX;
//	}
	priority_queue<pii,vector<pii>,greater<pii> > q;
	q.push({0,st});
	anss[st]=0;
	while(!q.empty()){
		auto t=q.top();q.pop();
		for(pii i:g[t.second]){
			if(vis[i.first]!=0)continue;
			if(!(i.second+t.first<=anss[i.first]))continue;
			anss[i.first]=i.second+t.first;
			q.push({anss[i.first],i.first});
			vis[i.first]=1;
		}
	}	
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	//n  地铁线路数
	//m 地铁站数
	//d 每个地铁站最多被几条线路经过
	//q 出行计划数
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		lines[i]=m+i;
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			ll a,t;
			cin>>a>>t;
			// a地铁站
			// t站台时间
			g[a].push_back({lines[i],t});
			g[lines[i]].push_back({a,t});
		}
	}
	
	
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ass[i]={x,y,i,0};
		
//		djstl(x);
//		cout<<anss[y]+w[x]+w[y]<<endl;
//		cout<<anss[y]<<endl;
//		for(int i=1;i<=10;i++)cout<<anss[i]<<' ';
//		cout<<endl;
		
	}
	sort(ass+1,ass+1+q,cpp);
//	cout<<ass[1].x<<" "<<ass[1].y<<" "<<ass[1].idx<<" "<<ass[1].ans<<" \n";
	int la=-11;
	for(int i=1;i<=q;i++){
		if(ass[i].x!=la){
			djstl(ass[i].x);
			la=ass[i].x;
		}
		ass[i].ans=anss[ass[i].y]+w[ass[i].x]+w[ass[i].y];
	}
	
//	cout<<ass[1].x<<" "<<ass[1].y<<" "<<ass[1].idx<<" "<<ass[1].ans<<" \n";
	sort(ass+1,ass+1+q,cpp2);
	
//	cout<<ass[1].x<<" "<<ass[1].y<<" "<<ass[1].idx<<" "<<ass[1].ans<<" \n";
	for(int i=1;i<=q;i++){
		cout<<ass[i].ans<<endl;
	}
	
	return 0;
}