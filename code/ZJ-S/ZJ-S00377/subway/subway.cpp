#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,inf=1e18;
ll y1[500005],y2[500005];
ll w[500005],dis[501005],f[501005],ans[100005];
struct N{
	ll x,w;
	bool operator <(const N& a) const{
		return w>a.w;
	}
}hy[1000005];
struct Q{
	ll x,y,id;
}qx[100005];
bool cmp(Q x,Q y){
	return x.x<y.x;
}
vector<N> t[501005];
void bfs(ll id,ll x){
	dis[x]=0;
	f[x]=id;
	queue<N> q;
	q.push({x,0LL});
	while(q.size()){
		auto p=q.front();
		q.pop();
		if(p.w>dis[p.x]) continue;
		for(auto to:t[p.x]){
			if(f[to.x]!=id){
				f[to.x]=id,dis[to.x]=inf;
			}
			if(p.w+to.w<dis[to.x]){
				dis[to.x]=p.w+to.w;
				q.push({to.x,dis[to.x]});
			}
		}
	}
}
int main(){
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(n==2LL){
		for(ll i=1;i<=m;i++){
			cin>>w[i];
			dis[i]=inf;
			y1[i]=y2[i]=-1;
		}
		for(ll i=1;i<=n;i++){
			ll x;
			cin>>x;
			for(ll j=1;j<=x;j++){
				ll k,l;
				cin>>k>>l;
				if(i==1){
					y1[k]=l;
				}else{
					y2[k]=l;
				}
			}
		}
		ll in=1e18;
		for(ll i=1;i<=m;i++){
			if(y1[i]!=-1&&y2[i]!=-1){
				in=min(in,y1[i]+y2[i]);
			}
		}
		while(q--){
			ll x,y,ans=1e18;
			cin>>x>>y;
			if(y1[x]!=-1){
				if(y1[y]!=-1){
					ans=min(ans,y1[x]+y1[y]);
				}
				if(in!=1e18&&y2[y]!=-1){
					ans=min(ans,y1[x]+in+y2[y]);
				}
			}
			if(y2[x]!=-1){
				if(y2[y]!=-1){
					ans=min(ans,y2[x]+y2[y]);
				}
				if(in!=1e18&&y1[y]!=-1){
					ans=min(ans,y2[x]+in+y1[y]);
				}
			}
			cout<<ans+w[x]+w[y]<<"\n";
		}
		return 0;
	}
	if(d==2LL){
		for(ll i=1;i<=m;i++){
			cin>>w[i];
			dis[i]=inf;
		}
		for(ll i=1;i<=n;i++){
			ll x;
			cin>>x;
			for(ll j=1;j<=x;j++){
				ll k,l;
				cin>>k>>l;
				if(hy[k*2].x){
					hy[k*2+1].x=m+i;
					hy[k*2+1].w=l;
					t[hy[k*2].x].push_back({hy[k*2+1].x,hy[k*2].w+hy[k*2+1].w});
					t[hy[k*2+1].x].push_back({hy[k*2].x,hy[k*2].w+hy[k*2+1].w});
				}else{
					hy[k*2].x=m+i;
					hy[k*2].w=l;
				}
			}
		}
		ll ct=0LL;
		while(q--){
			ll x,y;
			cin>>x>>y;
			ll ans=1e18;
			if(hy[x*2].x){
				++ct;
				bfs(ct,hy[x*2].x);
				if(hy[y*2].x){
					ans=min(ans,dis[hy[y*2].x]+hy[y*2].w+hy[x*2].w);
				}
				if(hy[y*2+1].x){
					ans=min(ans,dis[hy[y*2+1].x]+hy[y*2+1].w+hy[x*2].w);
				}
			}
			if(hy[x*2+1].x){
				++ct;
				bfs(ct,hy[x*2+1].x);
				if(hy[y*2].x){
					ans=min(ans,dis[hy[y*2].x]+hy[y*2].w+hy[x*2+1].w);
				}
				if(hy[y*2+1].x){
					ans=min(ans,dis[hy[y*2+1].x]+hy[y*2+1].w+hy[x*2+1].w);
				}
			}
			cout<<ans+w[x]+w[y]<<"\n";
		}
		return 0;
	}
	for(ll i=1;i<=m;i++){
		cin>>w[i];
		dis[i]=inf;
	}
	for(ll i=1;i<=n;i++){
		ll x;
		cin>>x;
		dis[m+i]=inf;
		for(ll j=1;j<=x;j++){
			ll k,l;
			cin>>k>>l;
			t[m+i].push_back({k,l});
			t[k].push_back({m+i,l});
		}
	}
	ll ct=0LL;
	for(ll i=1;i<=q;i++){
		cin>>qx[i].x>>qx[i].y;
		qx[i].id=i;
	}
	sort(qx+1,qx+1+q,cmp);
	ll lt=0LL;
	for(ll i=1;i<=q;i++){
		if(qx[i].x!=lt){
			bfs(lt+1,qx[i].x);
		}
		lt=qx[i].x;
		ans[qx[i].id]=dis[qx[i].y]+w[qx[i].x]+w[qx[i].y];
	}
	for(ll i=1;i<=q;i++){
		cout<<ans[i]<<"\n";
	}
	return 0;
}