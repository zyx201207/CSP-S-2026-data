#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen(crystal.cpp);
	//freopen("kun.out", "w", stdout);
	long long a,b,d=0,f=0,g=0,h=0;
	cin>>a>>b;
	long long c[a+2],e=b;
	for(int l=1;l<=a;l++)cin>>c[l];
	for(int i=1;i<=a;i++){
	for(int l=1;l<=a;l++){
	if(c[l]>c[i]){
	d=c[i];
	c[i]=c[l];
	c[l]=d;
	d=0;
	}
	}
	}
	for(int l=1;l<=a;l++){
	e=b;
	d=0;
	h=0;
	for(int i=1;i<=a;i++){
	e=e-(c[l]-c[i]);
	if(e>0)d++;
	if(d>f)f=d;
}
	}
	cout<<f-1;
	return 0;
}