#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll m,n,a[500005],sum=0,c,cz=-1,flag=0;
vector<ll> e[5005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=2;i<=n;i++){
		c=a[i]-a[i-1];
		if(cz!=-1){
			if(cz!=c){
				flag=1;
				break;
			}
		}else{
			cz=c;
		}
	}
	if(flag==0){
		m/=c;
		ll l=0,r=n;
		while(l<=r){
			ll mid=(l+r)/2;
			if(mid*mid+mid<=2*m){
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		cout<<l;
		return 0;
	}
	for(ll i=n-1;i>=1;i--){
		e[n].push_back(a[n]-a[i]);
	}
	for(ll i=n-1;i>=1;i--){
		for(ll j=1;j<i;j++){
			e[i].push_back(e[i+1][j]-e[i+1][0]);
		}
	}
	for(ll i=2;i<=n;i++){
		ll cnt=0,p=m;
		for(ll t:e[i]){
			if(p>=t){
				p-=t;
				cnt++;
			}else{
				break;
			}
		}
		sum=max(sum,cnt);
	}
	cout<<sum+1;
	return 0;
}
