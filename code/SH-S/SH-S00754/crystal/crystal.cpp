#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long a[5*100000+5],sum[5*100000+5];
long long n,m;
bool check(int id,long long tar,long long num){
	long long need=tar*num-(sum[id]-sum[id-num-1]);
	if(need<=m) return true;
	else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		long long l=0,r=i+1;
		while(l<r){
			long long mid=(l+r)/2;
			if(check(i,a[i],mid)) l=mid+1;
			else r=mid;
		}
		ans=max(ans,l-1);
	}
	cout<<ans;
} 
