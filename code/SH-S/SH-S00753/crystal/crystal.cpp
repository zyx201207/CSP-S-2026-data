#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
ll a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); 
	int n; ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	ll ans=0,now=0;
	for(int i=1;i<=n;i++){
		while(now<=i){
			ll l=s[i]-s[now];
			ll r=a[i]*(i-now);
			if(l+m<r) now++;
			else break;
		}
		ans=max(ans,i-now);
	}
	cout<<ans;
	return 0;
} 
