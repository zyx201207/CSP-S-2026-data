#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long dp[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,k;
	cin >> n >> m;
	bool f=1,f2=1;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=i){
			f=0;
		}
		if(i==2){
			k=a[i]-a[i-1];
		}else if(a[i]-a[i-1]!=k){
			f2=0;
		}
	}
	sort(a+1,a+n);
	if(f!=1&&f2!=1){
		long long ans=-1;
		for(long long i=2;i<=n;i++){
			long long cnt=0,ansx=1;
			for(long long j=1;j<i;j++){
				if(cnt+a[i]-a[j]<=m){
					cnt+=a[i]-a[j];
					ansx++; 
				}else{
					break;
				}
			}
			if(a[i+1]==a[i]){
				while(a[i+1]==a[i]){
					i++; 
					ansx++;
				}
				i--;
			}
			ans=max(ans,ansx);
		}
		cout << ans;
	}else if(f==1){
		int ans;
		for(long long i=1;i<=n;i++){
			if(i*(i-1)/2>m){
				ans=i-1;
				break;
			}
		}
		cout << ans;
	}else if(f2==1){
		long long ans;
		for(long long i=1;i<=n;i++){
			if(i/k*(floor(n/((double)k))*k+k)/2 > m){
				ans=i-1;
				break;
			}
		}
		cout << ans;
	}//n/k*(floor(n/(double)k)*k+k)/2
	return 0;
}

