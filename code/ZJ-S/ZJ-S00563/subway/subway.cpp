#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mk make_pair
ll c,n,m,d,q,k[504],p[500004],w[500004],l,r;
vector<	vector<ll> > a(504),a2(504);
vector< vector<ll> > b(500004),b2(500004);
map<pair<ll,ll>,ll> ma,f;
deque<pair<ll,ll>> deq;
void bfs(){
	while(deq.size()){
		auto t=deq.front();
		deq.pop_front();
		if(t.first==r)
			return ;
		for(int i=1;i<=p[t.first];i++){
			auto t1=mk(t.first,b[t.first][i]);
			if(ma[t1]==0){
				ma[t1]=1;
				f[t1]=f[t]+2;
				deq.push_back(t1);
			}
		}
		for(int j=1;j<=k[t.first];j++){
			auto t1=mk(a[t.first][j],t.second);
			if(ma[t1]==0){
				ma[t1]=1;
				f[t1]=f[t];
				deq.push_front(t1);
				if(t1.first==r)
					return ;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			ll u,v;
			cin>>u>>v;
			a[i].push_back(u),a2[i].push_back(v);
			p[u]++;
			b[a[i][j]].push_back(i);
			b2[a[i][j]].push_back(a2[i][j]);
		}
	}
	while(q--){
		cin>>l>>r;
		for(int i=1;i<=p[l];i++)
			deq.push_front(mk(l,b[l][i])),ma[mk(l,b[l][i])]=1;
		bfs();
		for(int i=1;i<=n;i++)
			if(ma[mk(r,i)]==1){
				cout<<(f[mk(r,i)]+2)*a2[1][1]+w[l]+w[r]<<"\n";
				break;
			}
	}
	return 0;
}