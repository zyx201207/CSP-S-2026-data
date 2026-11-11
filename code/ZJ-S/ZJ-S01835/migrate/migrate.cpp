#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+10;
long long c,t,n,d;
long long x[MAXN],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		memset(x,0,sizeof(x));
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		ans=0;
		for(int i=1;i<n-2;i++){
			long long l=i,r=n,mid;
			while(l<r){
				mid=((l+r)>>1);
				if(x[mid]==x[i]+d){
					l=mid;
					break;
				}
				else if(x[mid]>x[i]+d)r=mid;
				else l=mid+1;
			}
			long long x1=l;
			long long x2=x1-1;
			if(x2-i<1)continue;
			r=n;
			while(l<r){
				mid=((l+r)>>1);
				if(x[mid]==x[x2]+d){
					l=mid;
					break;
				}
				else if(x[mid]>x[x2]+d)r=mid;
				else l=mid+1;
			}
			long long maxi=l;
			long long x3=x2-1;
			if(x3==i){
				ans+=maxi-x1;
				continue;
			}
			l=x1,r=n;
			while(l<r){
				mid=((l+r)>>1);
				if(x[mid]==x[x3]+d){
					l=mid;
					break;
				}
				else if(x[mid]>x[x3]+d)r=mid;
				else l=mid+1;
			}
			ans+=maxi-l;
		}
		printf("%lld\n",ans);
	}
	return 0;
}