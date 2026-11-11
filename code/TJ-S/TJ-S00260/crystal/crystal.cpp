#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
long long n,m,maxn=-1;
bool bbb; 
long long a[10000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)bbb=1;
	}
	if(n>5000&&bbb==0){
		long long cnt=0;
		for(int i=1;i<=n;i++){
			if(m>=i)m-=i;
			else break;
			cnt++;
		}
		cout<<cnt+1;
		return 0;
	}
	bbb=0;
	long long gc=a[2]-a[1];
	for(int i=3;i<=n;i++)if(a[i]-a[i-1]!=gc){
		bbb=1;
		break;
	}
	if(n>5000&&bbb==0){
		long long cnt=0;
		for(int i=1;i<=n;i++){
			if(m>=gc*i)m-=gc*i;
			else break;
			cnt++;
		}
		cout<<cnt+1;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		long long x=m,sum=0;
		for(int j=i;j>=1;j--){
			if(a[i]-a[j]<=x)x-=(a[i]-a[j]);
			else break;
			sum++;
		}
		maxn=max(maxn,sum);
		if(i<=maxn)break;
	}
	cout<<maxn;
	return 0;
} 
