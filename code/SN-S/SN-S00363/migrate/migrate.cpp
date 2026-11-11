//郭昕宇 西安市铁一中学 SN-S00363 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[2000005],mp[5005];
vector<ll>v[5000];
ll t,n;
struct node{
	ll a,b;
};
bool check(ll s,ll end){
	memset(mp,LONG_LONG_MAX,sizeof mp);
	t++;
	queue<node>q;
	q.push({s,0});
	ll cnt=0;
	ll minn=n+1;
	mp[s]=0;
	while(!q.empty()){
		ll k=q.front().a;
		ll tot=q.front().b;
		q.pop();
		if(tot>minn)continue;
		if(k==end&&tot==minn){
			cnt++;
		}
		if(k==end&&minn==n+1){
			minn=tot;
			cnt++;
		}
		for(ll i=0;i<v[k].size();i++){
			if(tot+1>mp[v[k][i]])continue;
			mp[v[k][i]]=tot+1;
			q.push({v[k][i],tot+1});
		}
	}
	if(cnt==2)return 1;
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll ccc,t;
	cin>>ccc>>t;
	while(t--){
		ll d;
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
			v[i].clear();
		}
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if(max(a[i],a[j])-min(a[i],a[j])<=d){
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		}
//		for(ll i=1;i<=n;i++){
//			for(ll j=0;j<v[i].size();j++){
//				cout<<v[i][j]<<" ";
//			}
//			cout<<"\n";
//		}
		ll ans=0;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				if(abs(a[i]-a[j])<=d)continue;
				if(check(i,j)){
					ans++;
				}
			}
		}
		cout<<ans/2<<"\n";
	}
	return 0;
}
