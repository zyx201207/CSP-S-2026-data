#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500010],d[500010],dp[5010][5010],dc;
bool A;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	dc=a[2]-a[1];
	for(int i=1;i<=n;i++){
		d[i]=a[i+1]-a[i];
		if(i>2){
			if(a[i]-a[i-1]!=dc) A=1;
		}
	}
	d[n]=0;
	if(!A){
		ans=1;
		for(long long i=1;;i++){
			m=m-i*dc;
			if(m<0) break;
			else ans++;
		}
		printf("%d",ans);
		return 0;
	}
	for(int k=2;k<=n;k++){
		for(int i=1,j=i+k-1;j<=n;i++,j++){
			dp[i][j]=dp[i][j-1]+d[j-1]*(k-1);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(dp[i][j]<=m&&j-i+1>=ans){
				ans=j-i+1;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
