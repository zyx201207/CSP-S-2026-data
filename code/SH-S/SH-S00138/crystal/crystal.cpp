#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=500005;
int n;
ll m,a[N],st[N][30],lg[N],sum[N];
void init(){
	for(int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++) st[i][0]=a[i];
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
ll query(int l,int r){
	int k=lg[(r-l+1)];
	return max(st[l][k],st[r-(1<<k)+1][k]);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	init();
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int i=1,j=1;i<=n;i++){
		ll tmp=llabs((query(j,i)*(i-j+1))-(sum[i]-sum[j-1]));
		while(j<i&&tmp>m) ++j,tmp=llabs((query(j,i)*(i-j+1))-(sum[i]-sum[j]));
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
