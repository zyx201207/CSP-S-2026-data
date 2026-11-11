#include<bits/stdc++.h>
using namespace std;
int n,cot,da=0,e,f;
long long m,z=0;
long long a[500005],c[500005],d[500005];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	a[0]=0;
	cin>>n>>m;
	cin>>a[1]>>a[2];
	e=a[2]-a[1],f=1;
	for(int i=3;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=e)
			f=0;
	}
	if(f=1){
		for(int i=1;;i++){
			z+=i*e;
			da++;
			if(z>=m){
				cout<<da;
				return 0;
			}
		}
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		c[i]=a[i+1]-a[i];
		d[i]=c[i];
	}
	for(int i=2;i<=n;i++){
		z=0,cot=0;
		for(int j=i-1;j>=1;j--)
			d[j-1]+=d[j];
		for(int j=i-1;j>=1;j--){
			z=z+d[j];
			if(z<=m)
				cot++;
			else 
				j=0;
		}
		for(int j=i-1;j>=1;j--)
			d[j-1]=c[j-1];
		da=max(da,cot);
	}
	cout<<da+1;
	return 0;
}
