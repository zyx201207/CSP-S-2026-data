#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,a[N],l,r,mid,cnt,sum;
bool check(int S){
	cnt=S,sum=0;
	for(int i=1;i<cnt;i++){
		sum+=a[cnt]-a[i];
	}
	if(sum<=m)return 1;
	for(cnt=S+1;cnt<=n;cnt++){
		sum=sum-(a[cnt-1]-a[cnt-S])+(a[cnt]-a[cnt-1])*(S-1);
		if(sum<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	l=1,r=n;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	printf("%lld",r);
	return 0;
}
