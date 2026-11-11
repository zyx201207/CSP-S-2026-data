#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N],mmax,m,b[N];
int andd(int a1,int a2)
{
	int s=1,h=0;
	while(a1!=0&&a2!=0)
	{
		int y1=a1%2,y2=a2%2;
		if(y1==y2&&y1==1)
		{
			h+=s;
		}
		a1/=2;a2/=2;
		s*=2;
	}
	return h;
}
int main()
{
	freopen("and.in","r",stdin),freopen("and.out","w",stdout);
	cin>>n>>m;
	bool bjB=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];mmax=max(mmax,a[i]);
		b[i]=a[i]+1;
		if(a[i]!=i-1) bjB=0;
	}
	sort(a+1,a+1+n);
	if(mmax<4)//²âÊÔ16.17 
	{
		int i=1,s0=0,s1=0,s2=0,s3=0;
		while(a[i]==0) s0++,i++;
		while(a[i]==1) s1++,i++;
		while(a[i]==2) s2++,i++;
		while(a[i]==3) s3++,i++;
		if(s3>=m)
		{
			cout<<3;
			return 0;
		}
		if(s3+s2>=m)
		{
			cout<<2;
			return 0;
		}
		if(s1+s3>=m)
		{
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	if(bjB==1)//²âÊÔBÌØÐÔ 14.15
	{
		int k=n-1,z=1;
		while(m!=0)
		{
			k-=z;z*=2;
			m/=2;
		}
		cout<<max(k,0);
		return 0;
	}
	bool bj=1;//ÅÐ¶ÏÊÇ·ñÎªAÌØÐÔ 13
	for(int i=1;i<=n;i++)
	{
		while(b[i]!=1)
		{
			if(b[i]%2==1)
			{
				bj=0;break;
			}
			b[i]/=2;
		}
	} 
	if(bj==1)//A
	{
		cout<<a[n-m+1];
		return 0;
	}
	if(m==1)//²âÊÔ6 
	{
		cout<<mmax;
		return 0;
	}
	mmax=0;
	if(m==2)//²âÊÔ8.9.10 
	{
		for(int i=1;i<=n;i++)
		{
			if(i>1) while(a[i]==a[i-2]) i++;
			for(int j=i+1;j<=n;j++)
			{
				while(a[j]==a[j-2]) j++;
				mmax=max(mmax,andd(a[i],a[j]));
			}
		}
		cout<<mmax;
		return 0;
	}
	int k=a[1];
	long long jy[N];
	jy[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		jy[i]=andd(jy[i-1],a[i]);
	}
	if(m==n)//²âÊÔ7 
	{
		
		cout<<jy[n];
		return 0;
	}
	if(m==n-1)//²âÊÔ11.12 
	{
		mmax=jy[n-1];
		int ya=a[n];
		for(int y=n-1;y>0;y--)
		{
			mmax=max(mmax,andd(jy[y-1],ya));
			ya=andd(ya,a[y]);
		}
		cout<<mmax;
		return 0;
	}
	
	cout<<0;
	return 0;
}

