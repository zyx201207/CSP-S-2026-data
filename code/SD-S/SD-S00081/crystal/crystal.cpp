#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
long long a[maxn+5],tot[maxn+5];
long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		tot[i]=tot[i-1]+a[i];
	}
	long long ans=0;
	for(long long i=1;i<=n;i++){
		long long l=0,r=i;
		while(l<r-1){
			long long mid=(l+r)/2;
			if((i-mid)*a[i]-(tot[i-1]-tot[mid-1])<=m)r=mid;
			else l=mid;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
} 
