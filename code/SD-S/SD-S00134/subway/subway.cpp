#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,n,m,d,qq,w[500086],k,a,t,vis[501][501],f[501],vis2[501];
map<ll,ll> times[501];
vector<ll> v[500001],road[500001];
struct node{
	ll op,num;
	bool friend operator < (node a,node b){
		return a.op < b.op;
	}
};
priority_queue<node> q;
void dj(ll s,ll e,ll cnt){
	q.push({0,s});
	f[s]=0;
	while(!q.empty()){
		ll tmp=q.top().num;
		q.pop();
		if(vis2[tmp]==cnt) continue;
		vis2[tmp]=cnt;
		for(auto it:road[tmp]){
			if(f[it]>=f[tmp]+vis[tmp][it]){
				f[it]=f[tmp]+vis[tmp][it];
				q.push({-f[it],it});
			}
		} 
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		ll last;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			v[a].push_back(i);
			times[i][a]=t;
			last=a;
		}
	}
	memset(vis,0x3f3f3f,sizeof vis);
	memset(f,0x3f3f3f,sizeof f);
	for(int i=1;i<=m;i++){
		if(v[i].size()>1){
			for(auto it:v[i]){
				for(auto its:v[i]){
					if(it==its) continue;
					road[it].push_back(its);
					vis[it][its]=min(vis[it][its],times[it][i]+times[its][i]);
					vis[its][it]=min(vis[its][it],times[its][i]+times[it][i]);
				}
			}
		}
	}
	while(qq--){
		ll l,r,cnt=1,minn=1e11;
		cin>>l>>r;
		for(int i=1;i<=n;i++){
			f[i]=1e11;
			vis2[i]=0;
		}
		for(int it:v[l]){
			for(int its:v[r]){
				dj(it,its,cnt);
				minn=min(minn,f[its]+times[it][l]+times[its][r]);
				cnt++;
			}
		}
		cout<<minn+w[l]+w[r]<<endl;
	}
	return 0;
}

