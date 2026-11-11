#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+10;
const ll inf=3e18+10;

ll op,n,m;
ll a[N],dist[N],sum[N];
ll pr[N],sf[N];
vector<ll> node[N];
priority_queue<ll,vector<ll>,greater<ll>>qe;
void s1(){
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	map<ll,ll>mp;
	for(int i=1,j=1;i<=n;i++){
		while(llabs(a[i]-a[j])<=m&&j<=n){
			j++;
		}
		sf[i]=j-1;
	}
	for(int i=n,j=n;i>0;i--){
		while(llabs(a[i]-a[j])<=m&&j>0){
			j--;
		}
		pr[i]=j+1;
		mp[pr[i]]++;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=mp[sf[i]-1];
	}
//	for(int i=1;i<=n;i++){
//		cout<<sf[i]<<" \n"[i==n];
//	}for(int i=1;i<=n;i++){
//		cout<<pr[i]<<" \n"[i==n];
//	}
	cout<<ans<<"\n";
}
void s2(){
	ll ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		node[i].clear();
		for(int j=1;j<i;j++){
			if(llabs(a[i]-a[j])<=m){
				node[j].push_back(i);
//				cout<<j<<" -> "<<i<<"\n";
			}
		}
	}
//	cout<<n<<" "<<m<<"\n";
	for(int i=1;i<=n;i++){
		while(qe.size()) qe.pop();
		for(int j=1;j<=n;j++){
			dist[j]=inf;sum[i]=0;
		}
		qe.push(i);
		dist[i]=0;
		while(qe.size()){
			ll u=qe.top();qe.pop();
//			if(dist[u]!=inf) continue;
			for(auto v:node[u]){
				if(dist[v]>dist[u]+1){
					dist[v]=dist[u]+1;
					sum[v]=1;
					qe.push(v);
				}
				else if(dist[v]==dist[u]+1){
					sum[v]++;
					qe.push(v);
				}
			} 
		}
		for(int j=i;j<=n;j++){
			if(sum[j]==2) {
				ans++;
//				cout<<i<<" "<<j<<"\n";
			}
//			cout<<dist[i]<<" "<<sum[i]<<"\n";
		}
	}
	cout<<ans<<"\n";
}
void solve(){
	cin>>n>>m;
	if(op>=13&&op<=14)s1();
	else s2();
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll t=1;
	cin>>op>>t;
	while(t--){
		solve();
	}
	return 0;
} 