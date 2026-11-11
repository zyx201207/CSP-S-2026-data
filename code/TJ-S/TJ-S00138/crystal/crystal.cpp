#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	if (n<=20000){
		sort(a+1,a+n+1);
		for (int i=1;i<=n;i++){
			s[i]=s[i-1]+a[i];
		}
		long long ans=0;
		for (long long i=n;i>=1;i--){
			for (long long j=1;j<=i;j++){
				if (a[i]*(i-j+1)-(s[i]-s[j-1])<=m){
					ans=max(ans,i-j+1);
				}
			}
		}
		cout<<ans;
	}
	else{
		long long k=a[2]-a[1];
		for (int i=1;i<=n;i++){
			if ((i-1)*(k+k*(i-1))/2>m){
				cout<<i-1;
				return 0;
			}
		}
	}
	return 0;
}
