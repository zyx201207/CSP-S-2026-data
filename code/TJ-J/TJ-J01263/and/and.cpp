#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,a[1000005],ys,c[17]={0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
long long b[1000005];
int px(int x,int y)
{
	return x>y;
}
int rjz(int t,int s,long long k)
{
	if(t<2)
	{
		for(int j=1;j<=s;j++)
		{
			t*=10;
		}
		k+=t;
		return k;
	}
	ys=t%2;
	t-=ys;
	for(int i=1;i<=s;i++)
	{
		ys*=10; 
	} 
	k+=ys;
	s++;
	t/=2;
	 return rjz(t,s,k);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,px);
	for(int i=1;i<=m;i++)
	{
		b[i]=rjz(a[i],0,0); 
	} 
	for(int j=1;j<m;j++)
	{
		long long j1=0,j2=0;
		int i=0;
		while(i<=16)
		{
			if(b[j]%10==b[j+1]%10&&b[j]%10==1)
			{
				j2=1;
				for(int l=1;l<=i;l++)
				{
					j2*=10;
				}
				j1+=j2;
			}
			if(i==16)
			{
				b[j+1]=j1;
				break;
			}
			b[j]/=10;
			b[j+1]/=10;
			i++;
		}
	}
	long long p=0;
	for(int i=1;i<=16;i++)
	{
		p+=b[m]%10*c[i];
		b[m]/=10;
	}
	cout<<p;
	return 0;
 } 
