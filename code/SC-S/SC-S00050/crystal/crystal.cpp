#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 5;
ll n,a[N],k,sum,m,tot,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1),ans=sum=1,k=1,tot=a[1];
	for(ll i=2;i<=n;i++){
		sum++;
		tot+=a[i];
		while(sum*a[i]-tot>m){
			tot-=a[k];
			sum--;
			k++;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}