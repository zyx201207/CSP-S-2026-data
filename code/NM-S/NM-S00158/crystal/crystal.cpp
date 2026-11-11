#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005],n,m,ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	ll t=a[n/2+1],cnt[500005],sum=0;
	for(ll i=1;i<=n;i++){
		cnt[i]=t-a[i];
	}
	for(ll i=n/2+1;i>=1;i--){
		if(cnt[i]>=0)sum+=cnt[i];
		if(sum<=m)ans++;
		else break;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
