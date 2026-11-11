#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N=5e5+500+5;
int c,n,m,d,q,go_out[N],k,a,t,go_a,go_b,dist[N];
bool st[N];
vector<pii> vec[N];
//floyd x
//dij   
void dj(int set_off,int intention){
	memset(st,0,sizeof(st));
	memset(dist,0x3f,sizeof(dist));
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push({0,set_off});
	dist[set_off]=0;
	while(pq.size()){
		pii tmp=pq.top();pq.pop();
		int w=tmp.first,u=tmp.second;
		st[u]=1;
//		cout<<"Now: ";
//		if(u>m) cout<<"N "<<u-m<<endl;
//		else cout<<u<<endl;
		for(auto tmp1:vec[u]){
			int wv=tmp1.second,v=tmp1.first;
			if(st[v]) continue;
//			cout<<"go: "<<v<<" "<<wv<<endl;
			if(dist[v]>dist[u]+wv){
				dist[v]=dist[u]+wv;
				pq.push({dist[v],v});
			}
		}
	}
	int ans=dist[intention]+go_out[intention]+go_out[set_off];
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>go_out[i];
	}
//	if(0<=c && c<=3 && n<=50 && m<=300) subtask_1_3();
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			if(vec[a].size()<d) vec[a].push_back({m+i,t});
			vec[m+i].push_back({a,t});
		}
	}
	for(int i=1;i<=q;i++){
		cin>>go_a>>go_b;
//		cout<<"GOTO: "<<go_a<<' '<<go_b<<endl;
		dj(go_a,go_b);
	}
	// 3152746
	return 0;
} 
