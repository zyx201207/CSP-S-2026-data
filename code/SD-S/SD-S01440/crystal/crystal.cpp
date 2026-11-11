#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],sum[N],l,r;
int check(int p){
	for(int j=1;j<=n-p+1;j++){
		if(p*a[j+p-1]-sum[j+p-1]+sum[j-1]<=m){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	l=1,r=n;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	while(l!=r){
		long long mid=(l+r+1)/2;
		if(check(mid)==0){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
}

