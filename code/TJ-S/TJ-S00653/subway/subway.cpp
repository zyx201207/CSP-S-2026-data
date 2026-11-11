#include<bits/stdc++.h>
#define ll long long
using namespace std;const int N=505,M=5e5+5;
int n,c,m,d,Q,k,u,x,y;ll w[N],t,D[N+M];
vector<pair<int,ll> >e[N];
struct node{
	int a;ll s;bool operator<(const node o)const{return s<o.s;}
};priority_queue<node>q;
void dijstra(int S){
	memset(D,0x3f,sizeof(D));
	q.push({S,D[S]=0});
	while(q.size()){
		node nd=q.top();
		q.pop();int u=nd.a,s=nd.s;
		for(int o=0;o<e[u].size();o++){pair<int,ll>p=e[u][o];
			int v=p.first;ll l=p.second;
			if(D[v]>s+l)q.push({v,D[v]=s+l});
		}
	}
}int main(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;int v=m+i;
		for(int j=1;j<=k;j++){
			cin>>u>>t;
			e[u].push_back({v,t});
			e[v].push_back({u,t});
		}
	}while(Q--){
		cin>>x>>y;
		dijstra(x);
		cout<<D[y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
