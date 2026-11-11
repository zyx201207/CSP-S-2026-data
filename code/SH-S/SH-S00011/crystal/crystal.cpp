#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,s[500005];
bool check(int x,int y){
	long long tmp=a[y]*(y-x+1)-(s[y]-s[x-1]);
	return tmp<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		long long l=0,r=i;
		while(l+1<r){
			long long mid=(l+r)/2;
			if(!check(mid,i)){
				l=mid;
			}
			else{
				r=mid;
			}
		}
		ans=max(ans,i-(l+1)+1);
	}
	printf("%lld",ans);
	return 0;
}
