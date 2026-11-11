#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],d[N],sum,n,m,tot,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int k=1;k<=n;k++){
		sum=0;
		tot=1;
		for(int i=1;i<=k;i++){
			d[i]=a[k]-a[i];
		}
		for(int i=k-1;i>=1;i--){
			if(sum+d[i]<=m){
				sum+=d[i];
				tot++;
			}
			else
				break;
		}
		ans=max(ans,tot);
	}
	printf("%lld",ans);
}
