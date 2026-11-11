#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
const long long J=20;
long long n, m;
long long a[N], s[N];
long long st[N][J], lg[N];
long long ans;
void init(){
	lg[0]=-1;
	for(long long i=1;i<=n;i++){
		lg[i]=lg[i>>1]+1;
		st[i][0]=a[i];
		s[i]=s[i-1]+a[i];
	}
	for(long long j=1;j<=J;j++)
		for(long long i=1;i+(1<<j)-1<=n;i++)
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	return;
}
long long Query(long long l, long long r){
	long long k=lg[r-l+1];
	return max(st[l][k],st[r-(1<<k)+1][k]);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	init();
	for(long long l=1,r=0;l<=n;l++){
		r=max(r,l-1);
		while(r<n && Query(l,r+1)*(r-l+2)-s[r+1]+s[l-1]<=m)
			r++;
		ans=max(ans,r-l+1);
	}
	cout<<ans<<endl;
	return 0;
}
