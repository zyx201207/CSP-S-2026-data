#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500010],p[500010],sum1[500010],sum2[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,k,cnt=0,l,r,maxn=-1e9;
	cin>>n>>k;
	l=n,r=n-1;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		p[i-1]=a[i]-a[i-1]; 
	}
	for(int i=n-1;i>=1;i--){
		sum1[i]=sum1[i+1]+p[i];
	}
	for(int i=n-1;i>=1;i--){
		sum2[i]=sum2[i+1]+sum1[i];
	}
	while(r>=1&&l>=r){
		while(sum2[r]-cnt<=k&&r>=1){
			maxn=max(maxn,l-r+1);
			r--;
			cnt+=sum1[l];
		}
		l--;
		cnt+=p[l]*(l-r+1);
	}
	cout<<maxn;
	return 0;
}

