#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll a[N];
ll s[N];
ll n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	ll cnt=1,ans=1;
	for(int i=2;i<=n;i++){
		while(cnt*a[i]-(s[i-1]-s[i-1-cnt])>m){
			cnt--;
		}
		ans=max(ans,cnt);
		cnt++;
	}
	cout<<ans+1;
	return 0;
}
