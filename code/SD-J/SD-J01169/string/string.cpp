#include <bits/stdc++.h>
using namespace std;
long long n,a[20005];
char c[20005];
long long sum=0,l1=0,r1=0;
long long sum1=0,sum2=0;
long long ans=0;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for ( int i=1; i<=n; i++ ) {
		scanf("%lld",&a[i]);
		cin >> c[i];
		sum+=a[i];
	} sum/=2;
	int l=1,r=n;
	sum1+=a[l],sum2+=a[r];
	l1=a[l],r1=a[r];
	while ( sum1<=sum&&sum2<=sum&&l<r ) {//
		//printf("%lld %lld %lld %d %d %lld %lld %lld\n",sum,sum1,sum2,l,r,l1,r1,ans);
		if ( l1>r1 ) {
			if ( c[l]!=c[r] ) {
				ans+=r1;
			} 
			l1-=r1;
			r--;r1=a[r];
			sum2+=a[r];
		}
		else {
			if ( l1<r1 ) {
				if ( c[l]!=c[r] ) {
					ans+=l1;
				} 
				r1-=l1;
				
				l++;l1=a[l];
				sum1+=a[l];
			}
			else {
				if ( c[l]!=c[r] ) {
					ans+=l1;
				} 
				
				sum1+=a[l],sum2+=a[r];
				l++,r--;l1=a[l],r1=a[r];
			}		
		}
		
	}long long w=max(sum1,sum2)-sum;
	w/=2;
	if ( sum1>sum )l1-=2*w;
	else r1-=2*w;
	if ( l1>r1 ) {
		if ( c[l]!=c[r] ) {
			ans+=r1;
		} 
		l1-=r1;
		r--;r1=a[r];
		sum2+=a[r];
	}
	else {
		if ( l1<r1 ) {
			if ( c[l]!=c[r] ) {
				ans+=l1;
			} 
			r1-=l1;
			
			l++;l1=a[l];
			sum1+=a[l];
		}
		else {
			if ( c[l]!=c[r] ) {
				ans+=l1;
			} 
			
			sum1+=a[l],sum2+=a[r];
			l++,r--;l1=a[l],r1=a[r];
		}		
	}	
	//printf("%lld %lld %lld %d %d %lld %lld %lld\n",sum,sum1,sum2,l,r,l1,r1,ans);
	printf("%lld\n",ans);
	return 0;
}
