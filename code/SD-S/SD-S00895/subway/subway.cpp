#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=2e5+10,N=501,Q=1e5+10;
ll ans[1001][1001];
const ll INF=0x3f3f3f3f;
priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > dl;
vector<vector<ll> > an;
ll c,n,m,d,q,w[M],k[N],a[N][M],x[Q],y[Q],t[N][M];
vector<vector<pair<ll,ll> > > mp;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	for(ll i=1;i<=q;i++) cin>>x[i]>>y[i];
	mp.resize(m+1);
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=k[i];j++){
			for(ll op=1;op<=k[i];op++){
				if(op==j) continue;
				mp[a[i][j]].push_back({a[i][op],t[i][j]+t[i][op]});
				mp[a[i][op]].push_back({a[i][j],t[i][j]+t[i][op]});
			}
		}
	}
	if(c>=12&&c<=15){
		for(ll i=1;i<=q;i++){
			vector<ll> an;
			an.resize(m+1);
			for(ll i=1;i<=m;i++) an[i]=INF;
			dl.push({0,x[i]});
			an[x[i]]=0;
			while(!dl.empty()){
				pair<ll,ll> ky=dl.top();
				dl.pop();
				ll jd=ky.second,qw=ky.first;
				for(auto j:mp[jd]){
					if(an[j.first]>an[jd]+j.second){
						an[j.first]=an[jd]+j.second;
						dl.push({j.second,j.first});
					}
				}
			}
			cout<<an[y[i]]<<"\n";
		}
	}
	else{
		memset(ans,0x3f,sizeof(ans));
		for(ll i=1;i<=m;i++) ans[i][i]=0;
		for(ll s=1;s<=m;s++){
			dl.push({0,s});
			while(!dl.empty()){
				pair<ll,ll> ky=dl.top();
				dl.pop();
				ll jd=ky.second,qw=ky.first;
				for(auto i:mp[jd]){
					if(ans[s][i.first]>ans[s][jd]+i.second){
						ans[s][i.first]=ans[s][jd]+i.second;
						dl.push({i.second,i.first});
					}
				}
			}
		}
		for(ll i=1;i<=q;i++)
			cout<<min(ans[x[i]][y[i]],ans[y[i]][x[i]])+w[x[i]]+w[y[i]]<<'\n';
	}
	return 0;
}
