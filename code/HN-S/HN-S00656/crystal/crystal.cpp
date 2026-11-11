#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0,min=100000,c;
	cin>>n>>m;
	long long a[n];
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=0;i<n;i++){
		if(a[i]==a[i+1]){
			ans++;
			a[i+1]=9735323;
		}
	}
		for(long long i=0;i<n;i++){
			if(a[i+1]-a[i]<min){
				min=a[i+1]-a[i];
				c=a[i+1];
				a[i+1]=145466737935793;
				a[i]=86498680597;
				if(m>=min){
				m-=min;
				ans++;
				break;
				}
			}
		}
		if(m==0){
			cout<<2;
			return 0;
		}
		for(long long i=0;i<n;i++){
			if(c-a[i]>=min){
				min=c-a[i];
				 
				if(m>min){
					m-=min;
					ans++;
				
				}else if(m==min){
					cout<<ans+2;
					return 0;
				}else{
					cout<<ans+2;
					return 0;
				}
				
			}
			
		}
			
		
	
	return 0;
}
