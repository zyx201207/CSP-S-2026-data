#include <iostream>
#include <cstring>
using namespace std;
int l=0,k=0;
int main(){
	int n,m,x,y,z;
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}for(int i=0;i<n;i++){
		x=a[i];
		for(int j=i+1;j<n;j++){
			y=a[j];
			k=a[i] and a[j];
			for(int t=1;t<=m-2;t++){
				z=a[j+t];
				k=k and z;
			}cout<<a[i]<<" "<<a[j]<<" "<<k<<endl;
			l=max(l,k);
		}
	}cout<<l;
	return 0;
} 
