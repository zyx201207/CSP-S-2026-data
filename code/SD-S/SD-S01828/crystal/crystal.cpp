#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m;
ll a[500010],b[500010];
int ans=0,ququ=0,asd=0,jkl=0,uio=0,ppp=0;
void  j(){
	
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]-1!=i)
		{
			ququ=1;
		}
		if(i>0)
		{
			asd=a[i]-a[i-1];
			if(i==1)
			{
				jkl=asd;
			}
			if(jkl!=asd)
			{
				uio=1;
			}
		}
	}
	if(ququ==0)
	{
		ll asdfghjkl=0;
		ppp=1;
		while(1)
		{
			asdfghjkl++;
			m=m-asdfghjkl*ppp;
			if(m<0)
			{
				break;
			}
			if(asdfghjkl==n)
			{
				break;
			}
		}
		printf("%lld",asdfghjkl);
		return 0;
	}
	else if(uio==0)
	{
		if(asd<0)
		{
			ppp=-asd;
		}
		else
		{
			ppp=asd;
		}
		ll asdfghjkl=0;
		while(1)
		{
			asdfghjkl++;
			m=m-asdfghjkl*ppp;
			if(m<0)
			{
				break;
			}
			if(asdfghjkl==n)
			{
				break;
			}
		}
		printf("%lld",asdfghjkl);
		return 0;
	}
	else
	{
		sort(a,a+n);
	}
	b[0]=0;
	for(int i=1;i<n;i++)
	{
		b[i]=a[i]-a[i-1]+b[i-1];
	}
	for(int i=n-1;i>1;i--)
	{
		b[i]=i*b[i];
		for(int j=0;j<i;j++)
		{
			b[i]-=b[j];
		}
	}
	ll ret=0,wa;
	for(int i=0;i<n;i++)
	{
		wa=0;
		for(int j=0;j<i;j++)
		{
			wa=b[i]-b[j];
			if(wa<=m && i-j>ret)
			{
				ret=i-j;
				break;
			}
		}
	}
	printf("%lld",ret+1);
	return 0; 
} 
