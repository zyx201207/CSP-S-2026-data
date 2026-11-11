#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],d[N];
int s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1){ // …∂“Ù
		printf("1\n");
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		d[i]=a[i+1]-a[i];
		s[i]=s[i-1]+d[i];
	}
	int l=1,r=0,sum=0;
	int ans=-1;
	while(r<=n-1){
		while(sum<=m&&r<=n-1){
			r++;
			sum+=d[r]*(r-l+1);
//printf("[%d,%d], sum=%d\n",l,r,sum);
		}
		ans=max(ans,(r-1)-l+1);
//printf("ans=%d\n",ans);
		while(sum>m){
			sum-=s[r]-s[l-1];
			l++;
//printf("[%d,%d], sum=%d\n",l,r,sum);
		}
	}
	printf("%lld\n",ans+1);
	return 0;
}

