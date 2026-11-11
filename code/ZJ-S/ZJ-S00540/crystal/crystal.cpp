#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,l=1,r,ans;
ll m,a[500010],sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(r=1;r<=n;r++){
		sum+=(a[r]-a[r-1])*(r-l);
		while(sum>m){
			sum-=a[r]-a[l];
			l++;
		}
//		printf("%d %d\n",l,r);
		ans=max(ans,r-l+1);
	}
	printf("%d",ans);
}