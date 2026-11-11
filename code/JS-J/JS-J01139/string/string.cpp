#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long x[n+1],sum=0;
	char a[n+1];
	for(long long i=1;i<=n;i++){
		cin>>x[i]>>a[i];
	}
	long long l=1;
	long long r=n;
		while(l<r){
			if(a[l]!=a[r]){
				if(x[l]<x[r]) sum+=x[l];
				else sum+=x[r];
			}
				if(x[l]<x[r]){
					 x[l]=0;
					 x[r]-=x[l];
				 }
				else{
					  x[l]-=x[r];
					  x[r]=0;
				}
			if(x[l]<=0){
				l++;
			}
			if(x[r]<=0){
				r--;
			}
			
		}
		cout<<sum;
	return 0;
}
