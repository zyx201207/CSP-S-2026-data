#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],sum[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1,f=0;
		for(int i=mid;i<=n;i++){
			if(a[i]*mid-sum[i]+sum[i-mid]<=m){
				ans=mid;l=mid+1;f=1;break;
			}
		}if(!f)r=mid-1;
	}
	cout<<ans;
	//15:25
	return 0;
}
//OHHHHH I love OI
//guess:yellow-
