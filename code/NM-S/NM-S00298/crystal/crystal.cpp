#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
bool flag1=1;
ll n,m,ans=0;
ll a[500010];
bool check(ll x){
	ll md=a[x],sum=0;
	for(int i=1;i<=x;i++){
		sum+=abs(a[x]-a[i]);
	}
	return sum<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    IO;
    cin>>n>>m;
    ll cha=0;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
    	if(i==2){
    		cha=a[i]-a[i-1];
		}
		else {
			if(a[i]-a[i-1]!=cha)flag1=0;
		}
	}
	if(flag1){
		ll i=1;
		while(m>0){
			if(m>=i){
				m-=i*cha;
				ans++;
				i++;
			}
			else break;
		}
		cout<<ans+1;
		return 0;
	}

	ll l=1,r=n,mid;
	while(l<=r){
		mid=l+(r-l)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
    return 0;
}
