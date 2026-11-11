#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N];
ll b[N];
ll c[N];
bool cmp(ll a,ll b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<n;++i)b[i]=a[i+1]-a[i];
	for(int i=2;i<=n;++i)c[i]+=c[i-1]+(ll)b[i-1]*(i-1);
	ll ans=1;
	for(int i=2;i<=n;++i){
		ll sum=0;
		sum+=c[i];
		if(sum<=m){
			ans=max(ans,(ll)i);
		}else{
			for(int k=1;k<=i-ans;++k){
				sum-=(a[i]-a[k]);
				if(sum<=m){
					ans=max(ans,(ll)i-k);
					break;
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
