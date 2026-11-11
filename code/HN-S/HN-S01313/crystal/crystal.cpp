#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,plus=0,ave,ishave=0,num=0,isfind=0,h;
	cin>>n>>m;
	int a[n+1],b[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		plus+=a[i];
	}
	ave=plus/n;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==ave)
		{
			ishave=1;
			break;
		}
	}
	if(ishave==0)
	{
		int a1=ave-1,a2=ave+1;
		while(isfind==0)
		{
			for(int i=1;i<=n;i++)
			{
				if((a[i]==a1) || (a[i]==a2))
				{
					ave=a[i];
					isfind=1;
				}
			}
			a1--;a2++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==ave)
		{
			h=i;
			break;
		}
	}
	int wz=h;
	while((m>0 && h>0))
	{
		h--;
		int del=a[wz]-a[h];
		m=m-del;
		if(m<0)
		{
			break;
		}
		a[h]=a[wz];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[wz])
		{
			num++;
		}
	}
	cout<<num<<endl;
	return 0;
}
