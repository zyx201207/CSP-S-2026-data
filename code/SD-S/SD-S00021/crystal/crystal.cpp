#include<bits/stdc++.h>
using namespace std;
int n,num;
long long a[500005],m;
int pd(long long t,long long l,int cy)
{
	t-=l*cy;
	if(t<=0)
		return cy+1;
	else
		return pd(t,l,cy+1);
}
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==1)
	{
		cout<<1;
		return 0;
	}	
	sort(a+1,a+n+1,cmp);
	if(n==2)
	{
		if(m>a[1]-a[2])
			cout<<2; 
		else
			cout<<1;
		return 0;
	}
	long long t=a[2],l=a[1]-a[2];
	bool p=true;
	for(int i=3;i<=n;i++)
	{
		if(t-a[i]==l&&p==1)
			t=a[i];
		else
			p=0;
	}
	if(p==true)
	{
		int o=pd(m,l,1);
		if(o>n)
			cout<<n;
		else
			cout<<o;
		return 0;
	}
	
	/*for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<endl;*/
	int u=m;
	for(int i=1;i<=n;i++)
	{
		m=u;
		int j=i+1;
		for( ;j<=n;j++)
		{
			if(m+a[j]-a[i]>=0)
				m+=a[j]-a[i];
			else
			{
				num=max(num,j-i);
				//cout<<i<<" "<<j<<" "<<j-i<<" "<<m<<endl;
				break;
			}
		}
		if(j==n+1)
		{
			num=max(num,j-i);
			cout<<num;
			return 0;
			//cout<<i<<" "<<j<<" "<<j-i<<" "<<m<<endl;
		}
		
	}
	cout<<num;
	return 0;
 } 
 /*
5 5
1 2 4 8 9
80f
 */
