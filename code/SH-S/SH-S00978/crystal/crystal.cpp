#include<bits/stdc++.h>
using namespace std;

const int N=500005;
long long n,m,a[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	long long res=0,ans=1;
	for(long long i=1,j=1;i<=n&&j<=n;i++){
		while(res<=m&&j<n){
			j++;
			res+=(a[j]-a[j-1])*(j-i);
			if(res<=m)
				ans=max(ans,j-i+1);
		}
		res-=(a[j]-a[i]);
	}
	cout<<ans;
	return 0;
}
