#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500050];
long long sum[500050];
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+a[i];
	}
	long long ans=0;
	for(int i=1;i<=n;++i){
		long long l=0,r=i,mid;
		while(l<r){
			mid=(l+r)>>1;
			if(a[i]*(i-mid)-sum[i]+sum[mid]<=m){
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,i-r);
	}
	cout<<ans<<endl;
	return 0; 
} 
/*

5 5
1 2 4 8 9



5 8
-3 -1 2 2 7



*/
