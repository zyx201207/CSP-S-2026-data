#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N];
int n,m;
int sum[N];
vector<int> sdl;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	sum[1]=0;
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]+(a[i]-a[i-1])*(i-1);
	}
	int k=upper_bound(sum+1,sum+n+1,m)-sum-1;
	int none,noco;
	int last=0;
	int maxn=k;
	int i=1;
	int k1;
	for(;i<=k;i++){
		int gg=sum[i]+(a[k]-a[i])*i;
		int m1=m;
		int l=1,r=n;
		while(l<=r){
			int mid=(l+r)>>1;
			int cost=sum[mid]-sum[i]-i*(a[mid]-a[i]);
			if(cost>m1) r=mid-1;
			else if(cost<m1) l=mid+1,k1=mid;
			else{
				k1=mid;
				break;
			}
		} 
		maxn=max(maxn,k1-i);
	}
	printf("%lld",maxn);
	return 0;
}