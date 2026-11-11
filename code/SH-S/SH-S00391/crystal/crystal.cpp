#include<bits/stdc++.h>
using namespace std;
long long m,n,cnt;long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long r=n;r>1;r--){
		for(long long l=r-1;l>=1;l--){
			if(a[r]-a[l]>m){break;}
			long long sum=0;sum=a[r]-a[l]+sum;if(sum>m)break;
			if(sum<=m)cnt=max(cnt,r-l+1);
		}
	}
	cout<<cnt;
	return 0;
}
