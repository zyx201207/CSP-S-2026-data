#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],ans=0,flag=1,gx,k,sum=0;
bool cmp(ll x,ll y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>a[1]>>a[2];
	gx=a[2]-a[1];
	for(ll i=3;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		if(a[i]-a[i-1]!=gx) flag=0;
	}
	if(flag==1){
		k=int(sqrt(m*2/gx));
		while(1){
			if((k+1)*k<=m*2/gx) break;
			k--;
		}
		cout<<k+1;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	if(sum-n<=m && a[1]>=0){
		cout<<n;
		return 0;
	}
	for(ll i=a[n];i>=a[1];i--){
		sum=0;
		ll j;
		for(j=1;j<=n;j++){
			if(i<a[j]) break;
			if(sum>=m){
				for(;;j++) if(a[j+1]!=a[j]) break;
				break;
			}
			sum+=(i-a[j]);
		}
		ans=max(ans,j);
	}
	cout<<ans;
	return 0;
}