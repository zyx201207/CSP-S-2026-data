#include<bits/stdc++.h>
using namespace std;
long long a[500010],sum[500010];
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=1,r=1,ans=0;
	while(l<=n){
		if(r<n&&a[r+1]*(r-l+1)-(sum[r]-sum[l-1])<=m){
			r++;
			ans=max(ans,r-l+1);
		}else{
			l++;
		}
	}
	cout<<ans;
	return 0;
}
