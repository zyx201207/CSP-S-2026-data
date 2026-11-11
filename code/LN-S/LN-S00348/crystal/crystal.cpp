#include <bits/stdc++.h>
using namespace std;
int n,m,a[5000005],b[5000005],d;
int f(int x,int y){
	int c=0;
	for(int i=x;i<y;i++){

		c+=a[y]-a[i];
		
		if(c>m){
			return -1000;
		}
	}
	return y-x+1;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);

	for(int i=1;i<=n;i++){

		for(int j=i;j<=n;j++){

			if(f(i,j)>=-999){

				d=max(d,f(i,j));
			}
		}
	}cout<<d;
	return 0;
}
