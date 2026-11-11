#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,w[500005],k[505],f[505][505];
struct node{
	ll a,t;
	bool operator<(const node &x)const{
		return a<x.a;
	}
};
vector<node> v[505];
vector<node> st[500005];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			ll x,y;
			cin>>x>>y;
			st[x].push_back((node){i,y});
			v[i].push_back((node){x,y});
		}
		sort(v[i].begin(),v[i].end());
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			ll bst=1e18;
			for(ll iF=0,iS=0;iF<v[i].size()&&iS<v[j].size();){
				if(v[i][iF].a==v[j][iS].a){
					bst=min(bst,v[i][iF++].t+v[j][iS++].t);
				}
				else if(v[i][iF].a<v[j][iS].a){
					iF++;
				}
				else{
					iS++;
				}
			}
			f[i][j]=f[j][i]=bst;
		}
	}
	for(ll l=1;l<=n;l++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][l]+f[l][j]);
			}
		}
	}
	/*for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			cout<<f[i][j]<<" ";
		}
		cout<<'\n';
	}*/
	for(ll i=1;i<=q;i++){
		ll l,r;
		cin>>l>>r;
		ll ans=1e18,stIO=w[l]+w[r];
		for(ll iL=0;iL<st[l].size();iL++){
			for(ll iR=0;iR<st[r].size();iR++){
				ll L=st[l][iL].a,R=st[r][iR].a,T=st[l][iL].t+st[r][iR].t;
				ans=min(ans,stIO+T+f[L][R]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

