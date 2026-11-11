#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[510000],f,mx,maxa=-1,b[210];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])f=1;
		maxa=max(maxa,abs(a[i]));
	}
	if(!f){
		ll l=0,r=n,ans=-1;
		while(l<=r){
			ll mid=(l+r)/2;
			if(mid*(mid+1)*(a[2]-a[1])/2ll<=m){
				ans=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		cout<<ans+1;
		return 0;
	}
	else if(maxa<=100){
		for(int i=1;i<=n;i++){
			b[a[i]+100]++;
		}
		for(ll i=0;i<=200;i++){
			ll sum=0,cnt=0;
			for(ll j=i;j>=0;j--){
				sum+=b[j]*(i-j);
				cnt+=b[j];
				if(sum>=m){
					cnt-=ceil((sum-m)*1.0/(i-j));
					mx=max(mx,cnt);
					break;
				}
			}
		}
		cout<<mx;
		return 0;
	}
	else{
		sort(a+1,a+1+n);
		for(ll i=2;i<=n;i++){
			ll sum=0;
			for(ll j=i-1;j>=1;j--){
				sum+=a[i]-a[j];
				if(sum<=m){
					mx=max(mx,i-j+1);
				}
			}
		}
		cout<<mx;
		return 0;
	}
	return 0;
}