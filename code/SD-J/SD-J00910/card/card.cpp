#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,a[5005],b[1005][3],b1[1005],q[5005],h,t;
	memset(b,0,sizeof(b));
	memset(b1,0,sizeof(b1));
	cin>>n>>m;
	h=1,t=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]][1]==1)
			{
				for(int x=b[a[j]][2];x<=j;x++)
				{
					b[q[x]][1]=0;
					q[x]=0;
				 } 
				 t=b[a[j]][2]-1;
			}
			t++;
			q[t]=a[j];
			b[a[j]][1]=1;
			b[a[j]][2]=t;
		}
		for(int y=1;y<=m;y++)
		{
			cout<<b[y][1]<<" ";
			b1[y]+=b[y][1];
		}
		cout<<endl;
			memset(b,0,sizeof(b));
	}
	for(int y=1;y<=m;y++)
		{
			cout<<b1[y]<<" ";
		}
	return 0;
 } 
