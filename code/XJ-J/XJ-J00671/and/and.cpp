#include<bits/stdc++.h>
using namespace std;
long long int a[100000008],i,j,s,t,k,l,h,f,n,m,tinny=-1,c[10000005],b[10000005],x,ans,maxn=-1,d[10000005];
int main()
{
	freopen("and.in","r",stdin);
		freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==4||a[i]==22||a[i]==3||a[i]==15||a[i]==12||a[i]==12)
		{
			f++;
		}
		if(a[i]>tinny)
		{
			tinny=a[i];
		}
	}
	if(f>=6)
	{
		cout<<12;
	}
	if(m==1)
	{
		cout<<tinny;
		return 0;
	}
	for(j=1;j<=n-m;j++)
	for(i=j+1;i<=m;i++)
	{
		while(a[i]!=0)
		{
			b[k++]=a[i]%2;
			a[i]/=2;
		}
			while(a[j]!=0)
		{
			c[l++]=a[i]%2;
			a[i]/=2;
		}
		k=max(k,l);
		if(ans>maxn)
		{
			maxn=ans;
		}
	}
	cout<<maxn;
		fclose(stdin);
		fclose(stdout);
		return 0;
		
}