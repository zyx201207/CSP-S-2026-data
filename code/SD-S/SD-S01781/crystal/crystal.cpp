#include <bits/stdc++.h>
using namespace std;
long long a[510000],su[510000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m,ans=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		su[i]=su[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	for(int i=2;i<=n;i++){
		long long l=1,r=i,mid;
		mid=(l+r)/2;
		while(l<=r){
			mid=(l+r)/2;
			//cout<<mid<<' '<<i<<' '<<su[i]-su[mid]-(a[i]-a[mid])*(mid-1)<<"\n";
			if(su[i]-su[mid]-(a[i]-a[mid])*(mid-1) > m)l=mid+1;
			else {
				r=mid-1;
				ans=max(i-mid+1,ans);
			} 
		}
	}
	cout<<ans;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
} 
