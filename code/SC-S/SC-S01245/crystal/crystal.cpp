#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=1e6+10;
ll n,m,a[N],b[N],sm[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=1;i<n;i++)
		b[i]=a[i+1]-a[i];
	for(ll i=1;i<n;i++)
		sm[i]=sm[i-1]+b[i];
//	for(ll i=1;i<n;i++)
//		cout<<b[i]<<' ';
//	cout<<'\n';
//	for(ll i=1;i<n;i++)
//		cout<<sm[i]<<' ';
	ll sum=0,ans=0,cnt=1;
	for(ll i=1;i<n;i++){
		if(sum+cnt*b[i]<=m){
			sum+=cnt*b[i];
			cnt++;
		}else{
			sum+=cnt*b[i];
			cnt++;
			ll k=0;
			while(sum>m){
				sum-=sm[i]-sm[i-cnt+1];
				cnt--;
				k++;
				if(n-i<=k) break;
			}
			if(n-i<=k){
				ans=max(ans,cnt);
				cout<<ans;
				return 0;
			}
		}
	//	cout<<sum<<' ';
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}