#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sum=0,ans=0;
char c[200005];
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		a[i]=sum;
	}
	for(long long i=1;i<=sum/2;i++){
		long long f=sum+1-i;
		long long fi=lower_bound(a,a+n,i)-a;
		long long ff=lower_bound(a,a+n,f)-a;
		if(c[fi]!=c[ff])ans++;
	}
	cout<<ans;
	return 0;
}