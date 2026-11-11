#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],ans,cnt,sh;
map<long long,long long>ts,tw;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(ts[a[i]]){
			ts[a[i]]=ts[a[i]]+1;
		}
		else{
			ts[a[i]]=1;
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		if(!tw[a[i]]){
			tw[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i+=ts[a[i]]){
		cnt=0;
		long long l=1,r=tw[a[i]]-1;
		while(l<=r){
			long long mid=(l+r)>>1;
			if(a[i]*(tw[a[i]]-mid)-s[tw[a[i]]-1]+s[mid-1]<=m){
				cnt=tw[a[i]]-mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,cnt+ts[a[i]]);
	}
	printf("%lld",ans);
	return 0;
}
