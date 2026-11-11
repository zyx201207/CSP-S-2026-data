#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int q=1;q<=i;q++){
			if(a[i]>a[q]){
				swap(a[i],a[q]);
			}
		}
	}
	int z;
	for(int i=1;i<=m-1;i++){
		z= a[i] and a[i+1] ;
	}
	cout<<z;
	return 0;
}

