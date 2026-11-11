#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans=-1;
bool check(long long x){
	long long sum=0;
	for(long long i=1;i<x;i++){
		sum+=i;
	}sum*=a[1]-a[0];
	return sum<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n<=5000){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}sort(a,a+n);
		for(int i=0;i<n;i++){
			long long sum=m,cnt=0;
			for(int j=i-1;j>=0;j--){
				if(sum-a[i]+a[j]<0){
					break;
				}sum-=a[i]-a[j];
				cnt++;
			}
			ans=max(ans,cnt+1);
		}cout<<ans;
		return 0;
	}else{
		for(long long i=0;i<n;i++){
			cin>>a[i]; 
		}long long l=0,r=n;
		sort(a,a+n); 
		while(l<=r){
			long long m=(l+r)>>1;
			if(check(m))l=m+1;
			else r=m-1;
		}cout<<l-1;
	}
} 
