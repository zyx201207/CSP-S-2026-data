#include<bits/stdc++.h>
#define maxn 523456
#define int long long
using namespace std;
int n,m,a[maxn],diff[maxn],pre[maxn],l=1,r,ans;
int check(int k){
	int L=1,R=k-1,sum=0;
	for(int i=L;i<=R;i++)sum+=i*diff[i];
	int minn=sum;
	while(R<n-1){
		L++,R++;
		sum-=pre[R-1]-pre[L-2];
		sum+=(k-1)*diff[R];
		minn=min(minn,sum);
	}
	return minn<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++)diff[i]=a[i+1]-a[i];
	for(int i=1;i<=n-1;i++)pre[i]=pre[i-1]+diff[i];
	r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	printf("%lld\n",ans);
	return 0;
} 
