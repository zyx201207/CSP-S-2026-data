#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);

	for(ll i=2;i<=n;i++){
		int cnt=0;
		for(ll j=i-1;j>=1;j--){
			cnt+=a[i]-a[j];
			if(cnt>m){
				break;
			}
			else ans=max(ans,i+1-j);
		}
	}
	cout<<ans;
	return 0;
} 