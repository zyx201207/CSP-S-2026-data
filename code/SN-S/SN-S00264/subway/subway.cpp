#include<bits/stdc++.h>
using namespace std;
#define inf 20000000000000000
#define ll long long
const ll MAXM=5e5+10;
const ll MAXN=505;
ll c,n,m,d,q;
ll w[MAXM],k[MAXN];
map<int,long long> jz[MAXM];
ll jl[MAXN][MAXN];
vector<ll> zt[MAXM];
ll tim;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)
		cin>>w[i];
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			jl[i][j]=inf;
	
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			ll a,t;cin>>a>>t;
//			xla[i].push_back(a);
//			xlt[i].push_back(t);
//			add(i,a+n,t);
//			add(a+n,i,t);
			zt[a].push_back(i);
			jz[a][i]=t;
		}
	}
	for(ll p=1;p<=m;p++){
		for(ll i=0;i<zt[p].size();i++){
			for(ll j=i+1;j<zt[p].size();j++){
				jl[zt[p][j]][zt[p][i]]=jl[zt[p][i]][zt[p][j]]=min(jl[zt[p][i]][zt[p][j]],jz[p][zt[p][i]]+jz[p][zt[p][j]]);
			}
		}
	}
	for(ll i=1;i<=n;i++) jl[i][i]=0;
	for(ll p=1;p<=n;p++){
		for(ll i=1;i<=n;i++){
			if(p==i) continue;
			for(ll j=1;j<=n;j++){
				if(i==j||p==j) continue;
				jl[i][j]=jl[j][i]=min(jl[i][j],jl[i][p]+jl[p][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<i<<" "<<j<<" "<<jl[i][j]<<'\n';
//		}
//		cout<<'\n';
//	}
	for(ll p=1;p<=q;p++){
		ll st,ed;
		cin>>st>>ed;
		tim=inf;
		for(ll i=0;i<zt[st].size();i++){
			ll tmp1=zt[st][i];
			for(ll j=0;j<zt[ed].size();j++){
				ll tmp2=zt[ed][j];
//				cout<<tmp1<<" "<<tmp2<<" "<<jl[tmp1][tmp2]<<"\n";
				tim=min(tim,w[st]+w[ed]+jz[st][tmp1]+jz[ed][tmp2]+jl[tmp1][tmp2]);
			}
		}
		cout<<tim<<"\n";
	}
	return 0;
}
