#include<bits/stdc++.h>
using namespace std;
const long long maxn=6e5+7;
long long n,m,a[maxn],ans,sum[maxn];
int check(long long x,long long y){
	long long res=sum[y]-sum[x-1],tmp=a[y]*(y-x+1)-res;
	if(tmp<=m){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(long long i=1;i<=n;i++){
		long long l=1,r=i,mid,pos=i;
		while(l<r){
			mid=(l+r)>>1ll;
			if(check(mid,i)){			//mid is ok
				r=mid;
				pos=min(pos,mid);
			}
			else{						//mid is not ok
				l=mid+1;
			}
		}
		ans=max(ans,i-pos+1ll);
	}
	cout<<ans;
	return 0;
} 
