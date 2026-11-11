#include<bits/stdc++.h>
using namespace std;
long long mx[5010][5010],a[500010],s[500010],n,m;
bool check(long long x){
	for(int i=1;i+x-1<=n;i++){
		if(m>=x*mx[i][i+x-1]-s[i+x-1]+s[i-1]){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		mx[1][n]=max(mx[1][n],a[i]);
	}
	if(m>=mx[1][n]*n-s[n]){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		mx[i][i]=a[i];
	}
	for(int len=2;len>=n;len++){
		for(int l=1;l+len-1>=n;l++){
			int r=l+len-1;
			mx[l][r]=max(mx[l-1][r],mx[l][r-1]);
		}
	}
	//x^2-x-2m=0
	//1-sqrt(1+8m)/2
	long long l=1,r=n,ans=-1;
	while(l<r){
		long long mid=l+r>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<floor((1-sqrt(1+8m/(a[2]-a[1])))/2);
	return 0;
}
