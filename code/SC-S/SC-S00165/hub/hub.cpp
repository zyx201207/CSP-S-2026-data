#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
#define ll long long
ll c,T,n,m,k,ans;
bool next_com(ll a[],ll size,ll lim){
	for(ll i=size;i>=1;i--){
		if(a[i]+1<(i+1>size?lim+1:a[i+1])){
			a[i]++;
			for(ll j=i+1;j<=size;j++){
				a[j]=a[j-1]+1;
			}
			return 1;
		}
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		vector<ll>e[n+2];
		for(ll i=1;i<n;i++){
			ll u,v;
			cin>>u>>v;
			e[u].push_back(v),e[v].push_back(u);
		}
		ll a[n+2]={};
		for(ll i=1;i<=k;i++){a[i]=i;}
		ans=0x3fffffff;
		do{
			ll vis[n+2]={},sum=0;
			queue<ll>q;
			for(ll i=1;i<=k;i++){
				vis[a[i]]=1;
				q.push(a[i]);
			}
			for(ll i=1;i<=n;i++){
				if(vis[i]==1){
					for(ll j:e[i]){
						if(vis[j]==1){
							sum++;
							break;
						}
					}
				}
			}
			if(k-sum>2)continue;
			ll cnt=k,an=0;
			while(q.size()){
				ll t=q.front();q.pop();
				an=max(an,vis[t]-1);
				for(ll i:e[t]){
					if(vis[i]==0){
						vis[i]=vis[t]+1;
						q.push(i);
					}
				}
			}
			ans=min(ans,an);
		}while(next_com(a,k,n));
		cout<<ans<<'\n';
	}
	return 0;
}
