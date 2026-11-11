#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and1.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,arr[200000],max1=-1;
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int a=arr[i];
	        int b=arr[j];
	        int c=a&b;
	        if(c>max1){
	        	max1=c;
			}
		}
	}
	cout<<max1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}