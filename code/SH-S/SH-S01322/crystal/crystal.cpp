#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],s[500005],ans;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(ll i=1,j=1;i<=n;i++){
		while((i-j)*a[i]-s[i-1]+s[j-1]>m){
			j++;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}

