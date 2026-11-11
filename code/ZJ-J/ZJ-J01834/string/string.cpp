#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long m=0,n,arr[200001],num=0;
	char k[200001];
	cin>>n;
	for(int i=1;i<=n;i++) {
		
		cin>>arr[i]>>k[i];
		m+=arr[i];
	}
	m/=2;
	long long i=0,k1=1,k2=n;
	for(int l=1;l<=n;l++)
	{
		if(k1==k2)
		{
			cout<<num;
			return 0;
		}
		if(k[k1]==k[k2]) {
			if(arr[k1]>arr[k2]){
				i+=arr[k2];
				arr[k1]-=arr[k2];
				k2--;
				if(i>=m) {
					cout<<num;
					return 0;
				}
			}
			else if(arr[k1]==arr[k2]){
				i+=arr[k1];
				k1++;
				k2--;
				if(i>=m) {
					cout<<num;
					return 0;
				}
			}
			else {
				i+=arr[k1];
				arr[k2]-=arr[k1];
				k1++;
				if(i>=m) {
					cout<<num;
					return 0;
				}
			}
		}
		else {
			if(arr[k1]>arr[k2]){
				arr[k1]-=arr[k2];
				i+=arr[k2];
				num+=arr[k2];
				k2--;
			}
			else if(arr[k1]==arr[k2]){
				
				i+=arr[k1];
				num+=arr[k1];
				k1++;
				k2--;
			}
			else{
				arr[k2]-=arr[k1];
				i+=arr[k1];
				num+=arr[k1];
				k1++;
			}
			if(i>=m)
			{
				num-=(i-m);
				cout<<num;
				return 0;
			}
		}
	}
	return 0;
}

