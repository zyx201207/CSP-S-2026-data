#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005][32],ans,x[32];
void t1(int i)
{
	int t=0;
	int aa=a[i];
	while(aa>0)
	{
		b[i][++t]=aa%2;
		aa/=2;
	}
	b[i][0]=t;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		t1(i);
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=b[i][0];j>=1;j--)
			if(b[i][j]==1)
				x[j]++;
	}
	int mx1=-1,mx2=0;
	for(int i=30;i>=1;i--)
	{
		mx1=max(mx1,x[i]);
		if(mx1>=m)
		{
			mx2=i;
			break;
		}
	}
	int flag=1;
	while(flag)
	{
		flag=0;
		memset(x,0,sizeof(x));
		int z=1;
		for(int i=1;i<mx2;i++)z*=2;
		ans+=z;
		for(int i=1;i<=n;i++)
		{
			if(b[i][0]==-1||!b[i][mx2])
			{
				b[i][0]=-1;
				continue;
			}
			for(int j=mx2-1;j>=1;j--)
				if(b[i][j])x[j]++;
		}
		mx1=-1;
		for(int i=mx2-1;i>=1;i--)
		{
			mx1=max(mx1,x[i]);
			if(mx1>=m)
			{
				mx2=i;
				flag=1;
				break;
			}
		}
		
	}
	cout<<ans;
	return 0;
}