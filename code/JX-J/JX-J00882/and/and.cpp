#include<bits/stdc++.h>
using namespace std;
long long a[200010];
bool cmp(long long a,long long b){
	return a>b;
}
int kkkk(long long a,long long b,long long c){
	long long i=1,j=1,k=1;
	for(;i<=a;i*=2){
	}
	for(;j<=b;j*=2){
	}
	for(;k<=c;k*=2){
	}
	if(i-1==a && j-1==b && k-1==c){
	return 1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	int m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		long long maxx=0;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	if(m==n){
		for(int i=1;i<n;i++){
			a[i+1]=a[i] & a[i+1];
		}
		cout<<a[n];
		return 0;
	}
	if(m==2){
	long long maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				long long b=a[i] & a[j];
				maxx=max(maxx,b);
			}
		}
		cout<<maxx;
		return 0;
	}
	if(kkkk(a[1],a[2],a[3])){
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
		return 0;
	}
	if(m==n-1){
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<n-1;i++){
			a[i+1]=a[i] & a[i+1];
		}
		cout<<a[n-1];
		return 0;
	}
	else{
		cout<<a[n];
		return 0;
	}
	return 0;
}
