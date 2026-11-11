#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,n;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int number=1,z,k=0;
	for(int i=0;i<=n;i++){
		if(a[i+1]<a[i]){
			z=a[i];
			a[i]=a[i+1];
			a[i+1]=z;
		}
		if(a[i]==a[i+1]){
			number++;
		}
	}
	for(int j=n/2;j>=0;j--){
		
		k+=a[j]-a[j-1];
		a[j-1]=a[j];
		if(k>m){
			number+=0;
		}
		else{
			number++;
			k+=a[j]-a[1];
		}
	}
	cout<<number;
	return 0;
}



