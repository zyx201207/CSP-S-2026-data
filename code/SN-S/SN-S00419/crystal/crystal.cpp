#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll maxn,n,m,r=1,l=1,a[500010],sum[500010];
bool cmp(ll x,ll y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){ 	
		sum[i]=sum[i-1]+a[i];
	}
	for(r;r<=n;r++){
		ll del=r-l;
		maxn=max(maxn,del);

		ll num=a[r]*del-(sum[r-1]-sum[l-1]);
		while(num>m&&l<=r){
			num=num-(a[r]-a[l]);
			l++;
		}
	}
	cout<<maxn;
	return 0;
}

