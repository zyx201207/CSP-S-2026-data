#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef int ll;
const int N=1e6+10,M=1e3+10,MOD=1e9+7;
ll n,m,a[N],ans[N];
vector<ll> v;
bool vis[N];
int main(){
	fastio;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++){
		v.clear();
		for(ll j=1;j<=m;j++) vis[j]=false;
		for(ll j=i;j<=n;j++){
			if(!vis[a[j]]) v.push_back(a[j]); 
			else{
				while(v[v.size()-1]!=a[j]){
					vis[v[v.size()-1]]=0;
					v.pop_back();
				}
			}
			vis[a[j]]=j;
		}
		for(ll j=0;j<v.size();j++) ans[v[j]]++;
	} 
	for(ll i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
