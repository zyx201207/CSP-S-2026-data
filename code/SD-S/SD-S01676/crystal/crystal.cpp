#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500005],sum[500005];
bool check(int x,int R){
	long long lim=(R-x+1)*a[R+1];
	if(lim-(sum[R]-sum[x-1])<=m) return 1;
	else return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	ans=1;
	for(int i=2;i<=n;i++){
		int l=1,r=i-1,mid,L=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,i-1)){
				r=mid-1;
				L=mid;
			}
			else l=mid+1;
		}
		ans=max(ans,i-L+1);
	}
	printf("%d",ans);
	return 0;
}
//5 8
//-3 -1 2 2 7
