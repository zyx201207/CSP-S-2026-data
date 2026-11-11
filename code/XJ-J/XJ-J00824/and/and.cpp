#include<bits/stdc++.h>
using namespace std;
long long int i,l,r,n,m,a[1000005],maxn=-1,s=INT_MAX;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n,greater<int>());
	if(m==1)
	{
	cout<<a[1];	
	return 0;	
	}
	if(m==n)
	{
	for(i=1;i<=m;i++)	
	s=s&a[i];
	cout<<s;
	return 0;	
	}	
	else
	{
	l=1;r=m;	
	while(r<=n)
	{	
	for(i=l;i<=r;i++)	
	s=s&a[i];	
	if(s>maxn)	
	maxn=s;	
	l++;r++;
	s=INT_MAX;
	}		
	}
	cout<<maxn;
	return 0;
}
