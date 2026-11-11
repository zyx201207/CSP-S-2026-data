#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],b[n];
	int sum=100000000005;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		b[i]=a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n-1;i++){
		for(int j=1;j<n;j++){
			if(sqrt(a[i]-a[j])<sum){
				sum=sqrt(a[i]-a[j]);
				if(a[i]>a[j]){
					if(m>=sum){
						a[j]+=sum;
						b[j]=;
	                }
				}else if(a[i]<a[j]){
					if(m>=sum){
						a[i]+=sum;
						b[i]=1000000000000;
	                }
				}
			}
		}
	}
	int z=1000000000005;
	for(int i=0;i<n-1;i++){
		for(int j=1;j<n;j++){
			if(sqrt(b[i]-b[j])<z){
				z=sqrt(b[i]-b[j]);
				if(b[i]>b[j]){
					if(m>=z){
						a[j]+=z;
	                }
				}else if(a[i]<a[j]){
					if(m>=z){
						a[i]+=z;
	                }
				}
			}
		}
	}
	int x=0;
	for(int i=0;i<n;i++){
		if(a[i]==a[i+1]){
			++x;
		}
	}
	cout<<x;
	return 0;
} 
