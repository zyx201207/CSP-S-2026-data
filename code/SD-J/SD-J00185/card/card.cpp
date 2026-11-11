#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll a[5*N];
ll ans[5*N];
void clear(bool a[],ll pos){
	for(int i=1;i<=pos;i++){
		a[i]=false;
	}
}
void clearb(ll a[],ll pos){
	for(int i=1;i<=pos;i++){
		a[i]=0;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	ll pos=0;
	ll xb=1;
	ll maxx=-1;
	for(ll i=1;i<=n;i++){//¾ÖÊý 
		ll q[100010]={0};
		bool vis[100010]={false};
		for(ll j=i-1;j<=n;j++){
			if(!vis[a[j]]){
				q[xb]=a[j];
				vis[a[j]]=true;
				pos++;
				maxx=max(maxx,a[j]);
			}
			else{
				clearb(q,pos);
				pos=0;
				xb=1;
				q[xb]=a[j];
			}
			xb++;
		}
		for(ll k=1;k<=xb;k++){
			ans[q[k]]++;
		}
		xb=1;
		pos=0;
	} 
	for(ll i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
