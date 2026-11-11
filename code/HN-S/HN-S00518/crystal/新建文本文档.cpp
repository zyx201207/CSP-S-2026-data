#include <iostream>
#include <cstdio>
using namespace std;
int a[23][2],ans,x,minn=50000,xm,ym,xn=2000,yn=-2000;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		if(x<0)
		{
			a[x][1]++;
		}
		else
		{
			a[x][0]++;
		}
	}
	do
	{
		for(int j=1;j<20;j++)
		{
			for(int k=j+1;k<21;k++)
			{
				if(a[j][0]&&a[k][0])
				{
					if(j<xn) xn=j;
					if((k-j)*a[j][0]<minn)
					{
						minn=(k-j)*a[j][0];
						xm=k,ym=j;
					}
				}
			}
		}
		for(int j=0;j<20;j++)
		{
			for(int k=j+1;k<21;k++)
			{
				if(a[j][1]&&a[k][1])
				{
					if(k>yn) yn=k;
					if((k-j)*a[j][1]<minn)
					{
						minn=(k-j)*a[j][1];
						xm=j*-1,ym=k*-1;
					}
				}
			}
		}
		if((((xn+yn)*a[yn][1])<minn)&&(yn!=-2000))
		{
			minn=xn+yn;
			xm=xn,ym=yn*-1;
		}
		m-=minn;
		minn=50000;
		if(m>=0)
		{
			if(xm>=0)
			{
				if(ym>=0)
				{
					a[xm][0]+=a[ym][0];
					a[ym][0]=0;
				}
				else
				{
					a[xm][0]+=a[ym][1];
					a[ym*-1][1]=0;
				}
			}
			else
			{
				if(ym>=0)
				{
					a[xm][1]+=a[ym][0];
					a[ym][0]=0;
				}
				else
				{
					a[xm][1]+=a[ym][1];
					a[ym*-1][1]=0;
				}
			}
			xn=2000,yn=-2000;
		}
		else break;
		if(m==0) break;
	}while(1);
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<21;j++)
		{
			if(a[j][i]>1)
			{
				ans+=a[j][i];
				cout<<j<<' '<<i<<' '<<a[j][i]<<endl;
			}
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
