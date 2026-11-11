#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e6+5;
ll temp,n,d,t,a[N],cnt[N];
void dfs(ll s,ll e,ll x,ll cntt,ll add){
	if(x==e){
		cnt[cntt]++;
		return;
	}
	if(add+a[x+1]-a[x]<=d&&add)dfs(s,e,x+1,cntt,add+a[x+1]-a[x]);
	if(a[x+1]-a[x]<=d)dfs(s,e,x+1,cntt+1,a[x+1]-a[x]);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>temp>>t;
	while(t--){
		ll ans=0;
		cin>>n>>d;
		ll temp;
		bool flag=1;
		for(ll i=1;i<=n;++i){
			cin>>a[i];
		}
		if(n==1){
			cout<<"0\n";
			continue;
		}
		temp=a[2]-a[1];
		for(ll i=3;i<=n;++i){
			if(a[i]-a[i-1]!=temp){
				flag=0;
				break;
			}
		}
		if(!flag){
			for(ll i=1;i<n;++i){
				for(ll j=i+1;j<=n;++j){
					for(ll k=1;k<=j-i;++k){
						cnt[k]=0;
					}
					dfs(i,j,i,1,0);
					for(ll k=0;k<=j-i;++k){
						if(cnt[k]&&cnt[k]==2){
							++ans;
							break;
						}
						else if(!cnt[k]){
							continue;
						}
						else{
							break;
						}
					}
				}
			}
			cout<<ans<<"\n";
		}
		else{
			for(ll i=1;i<=1;++i){
				for(ll j=i+1;j<=n;++j){
					for(ll k=1;k<=j-i;++k){
						cnt[k]=0;
					}
					dfs(i,j,i,1,0);
					for(ll k=0;k<=j-i;++k){
						if(cnt[k]&&cnt[k]==2){
							ans+=(n-j+1);
							break;
						}
						else if(!cnt[k]){
							continue;
						}
						else{
							break;
						}
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}

