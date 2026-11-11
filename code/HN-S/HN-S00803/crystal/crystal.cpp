#include<bits/stdc++.h>
using namespace std;
long long n,a[1000000],m,k,cnt,b,c;
long long hsy(long long p){
	long long g=0;
	for(int j=1;j<=p;j++){
		if(a[p]==a[j]) continue;
		g=g+a[p]-a[j];
	}
	return g;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	c=n/2;
	for(int i=1;i<=101;i++){
		if(hsy(c)>m) c=c-(n-c)/200;
		if(hsy(c)<m) c=c+(n-c)/200;
	}
	cout<<c<<" "<<hsy(c);
	if(hsy(c)>m){
		for(int i=c;i>=1;i--){
		k=0;
		for(int j=1;j<=i;j++){
			k=k+a[i]-a[j];
		}
		if(k>=m) b=a[i],cnt=i;
		else{
			cnt=i;
			break;
		}
	}
	}
	else{
	for(int i=c;i<=n;i++){
		k=0;
		for(int j=1;j<=i;j++){
			k=k+a[i]-a[j];
		}
		if(k<=m) b=a[i],cnt=i;
		else break;
	}		
	}
	cout<<" "<<hsy(315275)<<" "<<m<<" "<<k<<" "<<cnt;
	return 0;
}
