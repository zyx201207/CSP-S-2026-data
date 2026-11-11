#include<bits/stdc++.h>
using namespace std;
long long n; 
long long m;
const int N=2*1e5+5;
long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n]; 
		return 0;
	}
	if(m==n){
		long long sum=a[1];
		for(int i=2;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum; 
		return 0;
	}
	if(m==2){
		long long ans=-123456789;
		long long sum;
		for(int i=1;i<=n;i++){
			sum=a[i];
			for(int j=i+1;j<=n;j++){ 
				if(sum&a[j]>ans){
					ans=sum&a[j];
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		long long ans=-123456789;
		long long sum;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){ 
				if(i==1){
					sum=a[2];
					sum=sum&a[j];
					if(sum>ans){
						ans=sum&a[j];
					}
				}
				else{
					sum=a[j];
					if(j!=i){
						sum=sum&a[j];
					}
					if(sum>ans){
						ans=sum&a[j];
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	
	
	
	return 0;
}
