#include<bits/stdc++.h>
using namespace std;
long long n,a[200100],t;
char b[200100],c,d;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		a[i]+=a[i-1];
		
	}
	t=a[n];
	long long l=1,r=a[n],s=0;
	//cout<<a[n];
	while(l<r){
		for(int i=1;i<=n/2;i++)if(l>=a[i]&&l<=a[i+1])c=b[i];
		for(int i=n/2+1;i<=n;i++)if(r>=a[i]&&r<=a[i+1])d=b[i];
		if(c!=d){
			s++;
		//	cout<<c<<' '<<d<<endl;
		}
		l++;r--;
	}
	cout<<s;
	return 0;
}
//aaaaabbb t=8
//
