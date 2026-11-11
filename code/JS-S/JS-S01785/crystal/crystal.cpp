#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],sum[500005],l,r,mid,cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    for(int i =1;i<=n;i++)
		a[i]=a[n]-a[i];
	for(int i=n;i>=1;i--)
	    sum[i]=sum[i+1]+a[i];	
	for(int i=1;i<=n;i++){
		l=1,r=i;
		while(l<=r){
		    mid=(l+r)/2;
		    if(sum[mid]-sum[i]-(i-mid)*a[i]>m)
		       l=mid+1;
		    else r=mid-1;
		}
		//cout <<l<<" "<<i<<"\n";//------
		cnt=max(cnt,i-l+1);
	}
    printf("%lld",cnt);
    return 0;
}
