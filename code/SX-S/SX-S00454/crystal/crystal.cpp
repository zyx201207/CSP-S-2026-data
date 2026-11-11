#include<iostream>
using namespace std;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],ssr[n],d[n],b=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	ssr[0]=a[0];
	d[0]=ssr[0]+m;
	for(int i=1;i<n;i++){
		b++;
		ssr[i]=ssr[i-1]+a[i];
		d[i]=(ssr[i]+m)/b;
		if(a[i]>d[i]){
			b--;
			ssr[i]=ssr[i-1];
		}
	}cout<<b;
	return 0;
}