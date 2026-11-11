#include<bits/stdc++.h>
using namespace std;
int a[500005]={};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		long long k;
		cin>>k;
		a[i]=k;
	}
	for(long long i=0;i<n-1;i++){
		for(long long j=i+1;j<n;j++){
			if(a[i]<a[j]){
				long long k=a[i];
				a[i]=a[j];
				a[j]=k;
			}
		}
	}
	long long x=0,y=0;
	for(y=0;y<n;y++){
		for(long long j=y+1;j<n;j++){
			x+=a[y]-a[j];
			if(x>m){
				x=0;
				break;
			}
		}
		if(x!=0)break;
	}
	cout<<n-y<<endl;
	return 0;
}
