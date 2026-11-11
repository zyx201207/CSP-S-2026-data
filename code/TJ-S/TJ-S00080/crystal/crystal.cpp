#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m,a[500005],b[500005] = {0},cnt = 0,ans = 0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n%2!=0){
		for(ll i = 1;i<=n;i++){
			b[i] = abs(a[(n+1)/2]-a[i]);
		}
		sort(b+1,b+n+1);
		for(ll i = 2;i<=n;i++){
			if(cnt<m){
				if(cnt+b[i]>m){
					cout<<ans+1;
					return 0;
				}
				ans++;
				cnt+=b[i];
			}
			else{
				break;
			}
		}
	}
	else{
		for(ll i = 1;i<=n;i++){
			b[i] = abs(a[(n+1)/2+1]-a[i]);
		}
		sort(b+1,b+n+1);
		for(ll i = 2;i<=n;i++){
			if(cnt<m){
				if(cnt+b[i]>m){
					cout<<ans+1;
					return 0;
				}
				ans++;
				cnt+=b[i];
			}
			else{
				break;
			}
		}
	}
	cout<<ans+1;
	return 0;
}
