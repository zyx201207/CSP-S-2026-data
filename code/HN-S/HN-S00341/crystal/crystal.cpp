#include <cstdio>
using namespace std;
long a[500005],n;
void quick(int,int);
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m;
	int cut=0;
	scanf("%d %lld",&n,&m);
	scanf("%d",&a[1]);
	scanf("%d",&a[2]);
	long long x=a[2]-a[1];
	bool y=true;
	for(int i=3;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]-a[i-1]!=x)y=false;
	}
	if(y)
	{
		for(int i=1;i<=n;i++)
		{
			m-=x*i;
			cut++;
			if(m-x*(i+1)<0)break;
		}
		printf("%d",cut);
			fclose(stdin);
			fclose(stdout);
		return 0;
	}
	quick(1,n);
	int max=0;
	for(int i=n;i>=1;i--)
	{
		int m1=m;
		cut=1 ;
		for(int f=1;;f++)
		{
			m1-=(a[i]-a[i-f]);
			cut++;
			printf("%d %d %d %d\n",a[i],a[i]-a[i-f],m1,cut);
			if(m1-(a[i]-a[i-f-1])<0||i-f<=1)break;	
		}
		if(cut>max)
		{
			max=cut;
		}
	}
	printf("%d",max);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

void quick(int r,int ll)
{
	if(r>=ll)return ;
	int i=r;
	int l1=ll;
	bool zt=0;
	while(l1!=i)
	{	
		
		if(a[l1]<=a[i]&&!zt)
		{
			int x=a[i];
			a[i]=a[l1];
			a[l1]=x;
			x=i;
			i=l1;
			l1=x;
			zt=!zt;
		}
		else if(a[l1]>a[i]&&zt)
		{
			int x=a[i];
			a[i]=a[l1];
			a[l1]=x;
			x=i;
			i=l1;
			l1=x;
			zt=!zt;
		}
		if(zt)l1++;
		else l1--;
	}
	quick(r,i-1);
	quick(i+1,ll);
	return ;
}
