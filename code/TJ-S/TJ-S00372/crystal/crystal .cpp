#include<bits/stdc++.h>//crystal 
using namespace std;
const long long Q=1e6;
long long a[Q],b[Q],d=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long i=0;i<n-1;i++){
		b[i]=a[i+1]-a[i];
	}
	for(long long i=0;i<n;i++){
		if(i==0) continue;
		long long w=m,k=1;
		for(long long j=i-1;j>=0;j--){
			w-=(a[i]-a[j]);
			if(w<0) break;
			k++;
		}
		d=max(d,k);
	}
	cout<<d;
	return 0;
}
