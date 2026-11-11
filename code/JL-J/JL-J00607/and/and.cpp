#include<bits/stdc++.h>
using namespace std;
int main(){
	
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
long long n=0,m;
cin>>n>>m;
int a[10001];
for(int i=0;i<n;i++)
{
	cin>>a[i];
}
sort(a,a+n);
int  sum=0,x;
for(int i=n-1;i>=m;i--)
{
	x=0;
	for(int j=i;j<i-m;j--)
	{
		x=x&a[j];
	}
	sum=max(sum,x);
}
cout<<sum;
return 0;
}
