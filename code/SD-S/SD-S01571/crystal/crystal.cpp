#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5; 
int n;
ll m;
ll a[N];
ll sum[N];
ll mx[N],ml=1,mr=1;
int main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	//freopen("crystal3.in","r",stdin);
	sum[0]=0;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		//printf("sum[%d]=%lld,",i,sum[i]);
	}
	//printf("\n");
	int l=1,r=1;
	mx[1]=a[1];
	int ans=0;
	while(l<=r&&r<=n){
		//printf("l=%d,r=%d\n",l,r);
		//printf("mx[ml]=%lld,sum[r]=%lld,sum[l-1]=%lld\n",mx[ml],sum[r],sum[l-1]);
		if(mx[ml]*(r-l+1)-sum[r]+sum[l-1]>m){
			//printf("%lld>m\n",mx[ml]*(r-l+1)-sum[r]+sum[l-1]);
			if(r==n)break;
			if(mx[ml]==a[l])ml++;
			l++;
		}
		else{
			ans=max(ans,r-l+1);
			//printf("%lld<=m  %lld\n",mx[ml]*(r-l+1)-sum[r]+sum[l-1],ans);
			r++;
			while(mx[mr]<a[r]&&mr>=ml)mr--;
			mx[++mr]=a[r];
		}
		//printf("\n");
	}
	printf("%d\n",ans);
	return 0;
} 
