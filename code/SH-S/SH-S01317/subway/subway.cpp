#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2000009;
ll c,n,m,d,q,ans,w[N];
bool vst[N];
vector<ll> t[N],l[N],k[509],kt[509];
void bfs(ll be,ll en,ll cnt){
	if(be==en){
		ans=min(ans,cnt);
		return;
	}
	for(ll i=0;i<l[be].size();i++){
		for(ll j=0;j<k[l[be][i]].size();j++){
			if(vst[k[l[be][i]][j]]==0){
				vst[k[l[be][i]][j]]=1;
				bfs(k[l[be][i]][j],en,cnt+t[be][i]+kt[l[be][i]][j]);
				vst[k[l[be][i]][j]]=0;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		ll cl,pl,ti;
		cin>>cl;
		for(ll j=1;j<=cl;j++){
			cin>>pl>>ti;
			t[pl].push_back(ti);
			l[pl].push_back(i);
			k[i].push_back(pl);
			kt[i].push_back(ti);
		}
	}
	for(ll i=1;i<=q;i++){
		ll st,fi;
		ans=1e18;
		cin>>st>>fi;
		for(ll j=1;j<=m;j++)
			vst[j]=0;
		vst[st]=1;
		bfs(st,fi,w[st]+w[fi]);
		cout<<ans<<endl;
	}
	return 0;
} 
