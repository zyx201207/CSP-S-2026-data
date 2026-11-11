#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500009],sum,ans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long j=1;
	for(long long i=2;i<=n;i++){
		sum+=(i-j)*(a[i]-a[i-1]);
		while(sum>m){
			sum-=a[i]-a[j];
			j++;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}

