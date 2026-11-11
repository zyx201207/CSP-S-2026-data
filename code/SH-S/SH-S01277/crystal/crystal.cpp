#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+9;
ll n,m;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll cnt=0,ans=0;
	for(ll r=2,l=1;r<=n;r++){
		cnt+=(a[r]-a[r-1])*(r-l);
		while(cnt>m){
			cnt-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
