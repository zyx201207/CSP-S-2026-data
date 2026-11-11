#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0;
	cin >> n >> m;
	for(long long i=1; i<=n; i++){
		cin >> a[i];
	}
	for(long long i=1; i<=n; i++){
		long long sums=0,sum=0;
		for(long long j=1; j<=n; j++){
			if(j!=i && a[j]<=a[i]){
				sum++;
				sums+=a[i]-a[j];
			}
		}
		if(sums<=m){
			ans=max(ans,sum+1);
		}
	}
	cout << ans;
	return 0;
} 