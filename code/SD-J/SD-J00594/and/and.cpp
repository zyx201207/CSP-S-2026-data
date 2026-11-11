#include<bits/stdc++.h>
using namespace std;
long long f(int a,int b)
{
	string a1="",b1="",c="";
	long long h=0,x=1;
	while(a>0) {a1+=a%2+48;a/=2;}
	while(b>0) {b1+=b%2+48;b/=2;}
	long long l=min(a1.size(),b1.size())-1;
	for(int i=l;i>=0;i--)
	{
		if(a1[i]==b1[i] && a1[i]==1) c+=49;
		else c+=48;
	}
	for(int i=0;i<c.size();i++) 
	{
		if(c[i]==1)h+=x;
		x*=2; 
	}
	return h;
} 
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[200005],ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1)
	{
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	} 
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			cout<<f(a[i],a[j])<<" ";	
	return 0;
} 
