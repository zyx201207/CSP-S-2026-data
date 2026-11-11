#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
ll n,a[500005],m,c[500005],ans=1,cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)c[i]=a[i]-a[i-1];
	for(int i=2;i<=n;i++){
		long long r=m,x=i-1;
		cnt=1;
		while(x>=1&&r>=(a[i]-a[x])){
			cnt++;r-=(a[i]-a[x]);x--;
		}
		ans=max(ans,cnt);
	}printf("%lld\n",ans);
	return 0;
}
