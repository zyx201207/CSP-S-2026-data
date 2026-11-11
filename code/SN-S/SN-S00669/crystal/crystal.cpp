#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[500000],m,c=0;
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}	
	for(int i=0;i<=m;i++){
		int z;
		if(a[i]>a[i+1]){
			z=a[i+1];
			a[i+1]=a[i];
			a[i]=a[i+1];
		}
	}
	int j=0,b=0,i=-1;
	while(j<=m){
		if(a[i]<a[i+1]){
			b=a[i+1]-a[i];
			j=b+j;
		}i=i+1;
		c++;
		if(j>m){
			c=c-1;
		}
	}
	cout<<c;
	return 0;
}
