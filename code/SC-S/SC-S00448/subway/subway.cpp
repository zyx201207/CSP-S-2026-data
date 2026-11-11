#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct road{
	int to;
	ll w;
};
int c,n,m,d,qq;
ll w[500050];
ll f[500550];
vector<road> rd[500550];
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t; cin>>a>>t;
			rd[m+i].push_back({a,t});
			rd[a].push_back({m+i,t});
		}
	}
	while(qq--){
		int s,t;
		cin>>s>>t;
		memset(f,0x3f,sizeof(f));
		f[s]=0;
//		while(!q.empty())q.pop();
		q.push({0,s});
		while(!q.empty()){
			ll si=q.top().first;
			int no=q.top().second;
			q.pop();
			if(si>f[no]) continue;
//			cout<<no<<endl;
			for(int i=0;i<rd[no].size();i++){
				ll gx=si+rd[no][i].w;
				if(gx<f[rd[no][i].to]){
					f[rd[no][i].to]=gx;
					q.push({gx,rd[no][i].to});
				}
			}
		}
		cout<<f[t]+w[s]+w[t]<<endl;
	}
	return 0;
}
