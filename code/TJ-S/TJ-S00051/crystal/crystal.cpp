#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500100],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool f = 1,f2 = 1;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i] != i)f = 0;
		if(i >= 2)if(a[i]-a[i-1] != a[i-1] - a[i-2])f2 = 0;
	}
	if(f){
		long long i = 1;
		long long n2 = n;
		while(n2--){
			if(m >= i){
				ans ++;
				m -= i;
				i++;
			}
			else break;
		}
		cout<<min(n,ans);
	}
	else if(f2){
		long long cha = abs(a[2]-a[1]);
		long long i = cha;
		long long n2 = n;
		while(n2--){
			if(m >= i){
				ans ++;
				m -= i;
				i+=cha;
			}
			else break;
		}
		cout<<min(n,ans);
	}
	else{
		sort(a+1,a+1+n);
		for(long long i=2;i<=n;i++){
			long long ma = 1,m2 = m;
			for(long long j=i-1;j>=1;j--){
				if(m2 >= a[i]-a[j]){
					m2 -= a[i]-a[j];
					ma ++;
				}
				else break;
			}
			ans = max(ans,ma);
		}
		cout<<ans;
	}
	return 0;
}
