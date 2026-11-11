#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+10;
ll n,m;
ll vis[N],wz[N],idx,b[N];
ll a[N];
ll cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(ll i=1;i<=n;i++){
		cin >> a[i];
	}
	for(ll i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		memset(wz,0,sizeof wz);
		memset(b,0,sizeof b);
		idx=0;
		for(ll j=i;j<=n;j++){
			if(vis[a[j]]==0){
				++idx;
				vis[b[idx]]=0;
				vis[a[j]]=1;
				b[idx]=a[j];
				wz[a[j]]=idx;
			}
			else{
				if(wz[a[j]] <= idx+1){
					idx=wz[a[j]];
				}
				else{
					++idx;
					wz[a[j]]=idx;
					vis[b[idx]]=0;
					b[idx]=a[j];
					vis[a[j]]=1;
				}
			}
		}
		for(ll j=1;j<=idx;j++){
			cnt[b[j]]++;
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
