#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
using namespace std;
long long a[200005],b[200005],qb[200005],hb[200005];
long long tot,p,h,xbq,xbh=1,ans=0,xbh_max=0,t;
char x[200005],s[200005],qb_x[200005],hb_x[200005];
int n,cnt=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>x[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(x[i+1]==x[i])
		{
			a[i]+=a[i+1];
			a[i+1]=0;
		}
		if(a[i]!=0)
		{
			b[++cnt]=a[i];
			s[cnt]=x[i];
		}
	}
	for(int i=1;i<=cnt;i++)
	{
		h+=b[i];
	}
	n=cnt;
	if(h%2==0)
	{
		tot=h/2;
	}
	else
	{
		tot=(h-1)/2;
	}
	p=tot;
	for(int i=1,j1=1,j2=0;i<=n;i++)
	{
		if(j2==0)
		{
			if(p>=b[i])
			{
				qb[j1]=b[i];
				qb_x[j1]=s[i];
				p-=b[i];
			}
			else
			{
				qb[j1]=p;
				qb_x[j1]=s[i];
				b[i]-=p;
				if(h%2!=0)
				{
					b[i]--;
				}
				j2=1;
				i--;
			}
			xbq+=1;
			j1++;
		}
		else
		{
			hb[j2]=b[i];
			hb_x[j2]=s[i];	
			xbh_max++;
			j2++;		
		}
	}	
	while(ans!=-1)
	{
		if(qb_x[xbq]!=hb_x[xbh])
		{
			ans+=min(qb[xbq],hb[xbh]);
		}
		t=min(qb[xbq],hb[xbh]);
		qb[xbq]-=t,hb[xbh]-=t;
		if(qb[xbq]==0)
		{
			xbq--;
		}
		if(hb[xbh]==0)
		{
			xbh++;
		}	
		if(qb[1]==0&&hb[xbh_max]==0)
		{
			break;
		}	
	}
	cout<<ans<<endl;
	return 0;
}
