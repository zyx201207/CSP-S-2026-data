#include<bits/stdc++.h>
using namespace std;
long long a[500010],sum[500010],m, cnt[110];
bool cmp(long long a,long long b){
	if(a<=b) return true;
	else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,ans=0,flag1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]&&a[i]!=i){
			flag1=0;
		}
	}
	if(n<=5000){
		sort(a+1,a+1+n);
		for(int i=n;i>=1;i--){
			sum[i]=sum[i+1]+a[i];
		}
		for(int j=1;j<=n;j++){
			long long maxx=0;
			for(int i=j;i<=n;i++){
				if(a[i]*(i-1)-sum[1]+sum[i]<=m){
					maxx++;
				}
			}
			ans=max(maxx,ans);
		}
	}
	else if(flag1){
		sort(a+1,a+1+n);
		for(int i=n;i>=1;i--){
			sum[i]=sum[i+1]+a[i];
		}
		for(int i=1;i<=n;i++){
			if(a[i]*(i-1)-sum[1]+sum[i]<=m){
				ans++;
			}
		}
	}
	else {
		for(int i=1;i<=n;i++){
			cnt[a[i]]++;
		}
		sort(a+1,a+1+n);
		for(int i=n;i>=1;i--){
			sum[i]=sum[i+1]+a[i];
		}
		int x=1;
		for(int j=1;j<=n;j+=cnt[x]){
			x++;
			long long maxx=0;
			for(int i=j;i<=n;i++){
				if(a[i]*(i-1)-sum[1]+sum[i]<=m){
					maxx++;
				}
			}
			ans=max(maxx,ans);
		}
	}
	cout<<ans;
	return 0;
}
