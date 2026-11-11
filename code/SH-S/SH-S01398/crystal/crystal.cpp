#include<iostream>
#include<cstdio>
#include<algorithm>
const int maxn=500001;
int n;
long long m;
long long a[maxn],s[maxn];
bool check(int x){
	long long sum=5*1e17+1; 
	for(int i=x;i<=n;i++)
		sum=std::min(sum,x*a[i]-s[i]+s[i-x]);
	return sum<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::cin>>n>>m;
	for(int i=1;i<=n;i++)std::cin>>a[i];
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=0,r=n;
	while(l<r-1){
		int mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	std::cout<<l;
	return 0;
}
