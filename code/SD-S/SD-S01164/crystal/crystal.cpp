#include<bits/stdc++.h>
using namespace std;
int a[100001],b[100001]={0};
int n,m,x=0,g=-1;
int adc(int x){
	int z=0,v=0;
	for(int j=x;j<=n;j++){
	v++;
	z=(b[j]*v)+z;
	if(z>m){
		return v;
	} 

	}
return v;
}
int main(){
	freopen("crystal.in","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
		for(int i=1;i<=n;i++){
		g=max(g,adc(i));
	}
	freopen("crystal.out","w",stdout);
	cout<<g;
	return 0;
} 
