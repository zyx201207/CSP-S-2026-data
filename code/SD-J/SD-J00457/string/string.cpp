#include<bits/stdc++.h>
using namespace std;char a[1000000000];long long as[100000000000];
int main1(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	long long sb=0;
	long long k=0;
	long long cnt=0;
	cin>>n;
	long long as[n];
	char as1[n];
	for(long long i=0;i<n;i++){
		cin>>as[i]>>as1[i];
		sb=sb+as[i];
	}
	
	for(long long i=0;i<n;i++){
		for(long long j=0;j<as[i];j++){
			a[k]=as1[i];
			k++;
			
		}
	}
	for(long long i=0;i<=sb/2;i++){
		if(!(a[i]==a[sb-i-1]))
		{
			a[i]=a[sb-i-1];
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	long long sb=0;
	long long k=0;
	long long cnt=0;
	cin>>n;
	
	char as1[n];
	for(long long i=0;i<n;i++){
		cin>>as[i]>>as1[i];
		sb=sb+as[i];
	}
	for(int i=0;i<=n/2;i++){
		if(!(as1[i]==as1[n-i-1])){
			if(as[i]<as[n-i-1]){
				for(int u=0;u<i+1;u++){
					as[n-i-1+u+1]=as[n-i-1+u];
					as1[n-i-1+u+1]=as1[n-i-1+u];
				}
				as[n-i-1]=as[n-i-1]-as[i];
				n++;
				
				cnt=cnt+as[i];
			}
			if(as[i]>as[n-i-1]){
					for(int u=i;u<n+1;u++){
					as[u+1]=as[u];
					as1[u+1]=as1[u];
					
				}
				n++;
				cnt=cnt+as[n-i-1];
			}
			if(as[i]==as[n-i-1]){
				cnt=cnt+as[n-i-1];
			}
			
			
			
			
		}
	}
	
	
	cout<<cnt;
	return 0;
} 
