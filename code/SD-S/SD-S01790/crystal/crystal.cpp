#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL N=5e5+5;
LL n,m,ans,a[N],sum[N];
LL check(LL p){
	LL l=1,r=p-1+1;
	while(l<r){
		int mid=(l+r)>>1;
		if(m+(sum[p-1]-sum[mid-1]-a[p]*(p-1-mid+1))>=0){
			r=mid;
		}else l=mid+1;
	}return p-l+1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
//	for(int i=1;i<=n;i++)
//		cout<<sum[i]<<' ';
	for(int i=1;i<=n;i++)
		ans=max(ans,check(i));
	cout<<ans;
//	cout<<check(4);
	return 0;
}
