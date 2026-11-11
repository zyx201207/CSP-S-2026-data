#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum,ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	sum=a[1];
	for(long long i=1,j=2;j<=n;j++){
		sum+=a[j];
		if(a[j]*(j-i+1)-sum>m){
			sum-=a[i];
			i++;
		}else{
			ans=max(ans,j-i+1);
		}
	}
	cout<<ans;
	return 0;
}
