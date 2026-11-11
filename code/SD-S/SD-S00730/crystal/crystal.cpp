#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
ll n,m,a[500005],s[500005],ans;
bool pd(int x,int y){
	ll sum;
	for(int i=y;i<x;i++)
		sum+=a[x]-a[i];
	return m>=sum;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++){
			if(pd(i,j)){
				ans=max(ans,(ll)i-j+1);
			}
		}
	printf("%lld",ans);
	return 0;
}
