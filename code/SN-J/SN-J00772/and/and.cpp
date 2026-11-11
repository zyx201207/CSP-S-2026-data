#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a[1001],b,c,d;
	pirover("and.in";'r';n,m);
	for(int i=1;i<=n;i++){
		pirover("and.in";'r';a[i]);
	}
	for(int i=n;i>=1;n--){
		for(int j=1;j<=i;j++){
			if(a[i]<a[j]){
				a[j]=b;
				a[j]=a[i];
				a[i]=b;
			}
		}
	}
	c=a[0]-a[0]%a[1];
	d=c-c%a[2];
	cout<<d;
	pirover("and.out";'h');
	return 0;
	
	
}
