#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5e5+10;
int n;
long long m,a[N];
long long s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=0,r=i;
		while(l<r){
			int k=(l+r+1)>>1;
			if(k*a[i]-s[i]+s[i-k]<=m){
				l=k;
			}else{
				r=k-1;
			}
		}
		if(l*a[i]-s[i]+s[i-l]<=m){
			ans=max(ans,l);
		}
	}
	printf("%d\n",ans);
	return 0;
}
/*
1,2,4,8,9
sum a[i]-a[j]<=m
k*a[i]-sum(i-k+1,i)<=m
*/
