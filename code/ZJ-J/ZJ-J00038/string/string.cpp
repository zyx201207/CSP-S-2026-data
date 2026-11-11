#include<bits/stdc++.h>
using namespace std;
int n;
long long sum;
long long a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%c%c",&a[i],&c[i],&c[i]);
		sum+=a[i];
	}	
	long long l=0,r=n,rs=a[n],ans=0;
	for(int i=1;i<=n;i++){
		if(i==r)
		    break;
		l+=a[i];
		if(l<=rs){
			ans+=1LL*(c[i]!=c[r])*a[i];
			continue;
		}  
		ans+=1LL*(c[i]!=c[r])*(rs-l+a[i]);
		while(l>rs){
			r--;
			if(i==r)
			    break;
			rs+=a[r];
			if(l<=rs)
			    ans+=1LL*(c[i]!=c[r])*(l-rs+a[r]);
			else
			    ans+=1LL*(c[i]!=c[r])*a[r];
		}
		if(i==r)
		    break;
	}
	printf("%lld",ans);
	return 0;
}
