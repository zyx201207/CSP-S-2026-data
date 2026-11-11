#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],m,n,cnt,ans;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n,cmp);
	for(long long i=1;i<n;i++){
		b[i]=a[i]-a[i-1];
		//printf("%d ",b[i]);
	}
	long long j;
	for(long long i=1;i<n;i++){
		j=i;
		while(m>b[j]){
			m+=b[j];
			j++;
			cnt++;
		}
		ans=max(ans,cnt);
		cnt=0;
	}
	printf("%lld",ans);
	return 0;
}
