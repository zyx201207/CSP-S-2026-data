#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int n,ans=1;
ll a[500005],m,b[500005];
bool check(ll x,ll y){
	ll s=b[y-1]-b[x-1];
	if((y-x)*a[y]-s<=m)return true;
	else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	for(int i=2;i<=n;i++){
		int l=1,r=i-1,mid;
		while(l<=r){
			mid=l+r>>1;
			if(check(mid,i))r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	printf("%d",ans);
	return 0; 
} 
