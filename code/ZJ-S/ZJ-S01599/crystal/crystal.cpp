#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long n,m,ans,a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(long long i=1;i<=n;i++){
		long long l=i,r=n+1;
		while(l+1<r){
			long long mid=(l+r)>>1;
			long long sum=b[mid]-b[i-1];
			long long U=a[mid]*(mid-i+1)-sum;
			if(U<=m){
				l=mid;
			}
			else{
				r=mid;
			}
		}
		ans=max(ans,l-i+1);
	}
	cout<<ans;
	return 0;
}
/*
只增不减 
i 在 [l,r]
那么最简单就是让所有的 j [l,r-1] 都变成 a_r 
*/
