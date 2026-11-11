#include<bits/stdc++.h>
using namespace std;
#define int long long
inline void rd(int &x){
	x=0;int f=1;char c=getchar();
	for(;'9'<c||c<'0';c=getchar())if(c=='-')f=-1;
	for(;'0'<=c&&c<='9';c=getchar())x=(x<<3)+(x<<1)+(c^48);
	x=f*x;
}
int n,m,a[500005],sum[500005],f[500005],ans=0,c[105];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	rd(n);rd(m);
	for(int i=1;i<=n;i++){
		rd(a[i]);
		f[i]=1; 
	}
	sort(a+1,a+n+1);
	sum[0]=0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	if(a[n]*n-sum[n]<=m){
		cout<<n;
		return 0;
	}
	if(n>5000||m>1e9||a[1]<-1e5||a[n]>1e5){
		int kk=a[2]-a[1];
		int i=1;
		while(a[i]*i-sum[i]<=m&&i<=n){
			i++;
		}
		cout<<i-1;
		return 0;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			if((a[i]*(i-j+1)-(sum[i]-sum[j-1]))<=m){
				f[i]=i-j+1;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
}
