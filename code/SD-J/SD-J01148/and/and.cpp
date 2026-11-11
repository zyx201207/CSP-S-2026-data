#include <iostream>
#include <cmath> 
using namespace std;
int n,m;
int a[200005];
bool A()
{
	for(int i=1;i<=n;i++)
		if(!((int)log2((double)a+1)==log2((double)a+1)))
			return 0;
	return 1;
}
int main()//ÍêÈ« 
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	if(m==1||A())
	{
		long long maxx=-1;
		for(int i=1;i<=n;i++)
			if(a[i]>maxx)
				maxx=a[i];
		cout<<maxx;
	}
	else if(m==2)
	{
		long long maxx=-1;
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				if(a[i]&a[j]>maxx)
					maxx=a[i]&a[j];
		cout<<maxx;
	}
	else if(m==n)
	{
		long long maxx=0;
		maxx=a[1];
		for(int i=2;i<=n;i++)
			maxx&=a[i];
		cout<<maxx;
	}
	else
		cout<<a[1];
	return 0;
} 
