#include<bits/stdc++.h>

using namespace std;

const int MAXN=500010;
long long n,m,o,k,R=0,R1=0;
long long a[MAXN],b[MAXN];

int jia(int y,int z)
{
	int d;
	int k=m;
	if(k>0&&k-(y-z)*b[z]>=0)
	{
		d=b[z];
		k=k-b[z];
	}
	else
	{
		if(k>0&&k-(y-z)*b[z]<0)	
		{
			for(int i=1;i<b[z];i++)
			{
				if(k-(y-z)*i>=0) 
				{
					k=k-(y-z)*i;
					d+1;
				}
				else
				{
					break;
				}
			}
		}
	}
	return d;
}
int ke(int x)
{
	o=b[x];
	for(int i=x-1;i>=1;i--)
	{
		int p=i;
		if(b[i]!=0)
		o=o+jia(x,p);
	}
	return o; 
}


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	int k=m;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=MAXN;i++)
	{
		b[a[i]]++;
	}
	b[0]=0;
	for(int i=-MAXN;i<=MAXN;i++)
	{
		R=b[i];
		R=R+ke(b[i]);
		if(R1>R) R1=R;
		R=0;
	}
	printf("%d",R1);
	return 0;
} 