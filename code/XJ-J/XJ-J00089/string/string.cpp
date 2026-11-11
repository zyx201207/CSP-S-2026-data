#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,count1=0,count2=0;
	cin>>n;
	char m,carr[n+1];
	long long arr[n+1];
	for(int i=0;i<n;i++){
		cin>>arr[i]>>carr[i];
		count2+=arr[i];
	}
	n--;
 	for(int i=0;i<=n;){
			if(carr[i]==carr[n-i]){
				if(arr[i]>arr[n-i]){
					arr[i]-=arr[n-i];
					n--;
				}else{
			
		if(arr[i]=arr[n-i]){
					n--;
					i++;
				}else{
				if(arr[i]<arr[n-i]){
					arr[n-i]-=arr[i];
					i++;
					
				}}}
			}else{
				if(arr[i]>arr[n-i]){
					arr[i]-=arr[n-i];
					n--;
					count1+=arr[n-i];
				}else{
				if(arr[i]=arr[n-i]){
					count1+=arr[n-i];
					n--;
					i++;
				}else{
				if(arr[i]<arr[n-i]){
					arr[n-i]-=arr[i];
					i++;
					count1+=arr[i];
				}}}
			}
		}
    if(count1<4){
    	count1/=2;
	}
	cout<<count1;
	return 0;
} 

