/*
#include<bits/stdc++.h>
#define int long long
#define rd read()
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		{
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,m;
const int N=1000005;
int a[N];
bool cmp(int q,int p)
{
	return q>p;
}
int ma=0;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=rd,m=rd;
	for(int i=1;i<=n;i++)
	{
		a[i]=rd;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		int sum=m,cnt=1;
		if(ma>=(n-i+1))
		{
			break;
		}
		for(int j=i+1;j<=n;j++)
		{
			int drt=a[i]-a[j];
			if(sum-drt<0)
			{
				break;
			}
			sum-=drt;
			cnt++;
		}
		ma=max(ma,cnt);
	}
	cout<<ma;
	return 0;
}
思路正确但时间复杂度过高
大样例4未过 
预计50pts 
*/

/*#include<bits/stdc++.h>
#define int long long
#define rd read()
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		{
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,m;
const int N=1000005;
int a[N];
bool cmp(int q,int p)
{
	return q>p;
}
int ma=0;
signed main()
{
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	n=rd,m=rd;
	int cc=0;
	bool e=true;
	for(int i=1;i<=n;i++)
	{
		a[i]=rd;
		if(i==2)
		{
			cc=a[i]-a[i-1];
		}
		if(i>2)
		{
			if(cc!=a[i]-a[i-1])
			{
				e=false;
			}
		}
	}
	if(e&&n>5000)
	{
		int xx=sqrt(cc*cc+8*m*cc);
		int xxx=((-cc+xx)/2)/cc;
		cout<<xxx;
		return 0; 
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		int sum=m,cnt=1;
		if(ma>=(n-i+1))
		{
			break;
		}
		for(int j=i+1;j<=n;j++)
		{
			int drt=a[i]-a[j];
			if(sum-drt<0)
			{
				break;
			}
			sum-=drt;
			cnt++;
		}
		ma=max(ma,cnt);
	}
	cout<<ma;
	return 0;
}
性质AB特供版
可解决等差数列问题 
预计75pts 
*/

#include<bits/stdc++.h>
#define int long long
#define rd read()
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		{
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,m;
const int N=1000005;
int a[N];
bool cmp(int q,int p)
{
	return q>p;
}
int ma=0;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=rd,m=rd;
	for(int i=1;i<=n;i++)
	{
		a[i]=rd;
	}
	sort(a+1,a+n+1,cmp);
	int sum=m,cnt=1;
	for(int i=1;i<=n;i++)
	{
		if(ma>=(n-i+1))
		{
			break;
		}
		for(int j=i+1;j<=n;j++)
		{
			int drt=a[i]-a[j];
			if(sum-drt<0)
			{
				break;
			}
			sum-=drt;
			cnt++;
		}
		ma=max(ma,cnt);
		break;
	}
	cnt--;
	sum+=(a[1]-a[2])*cnt;
	for(int l=2,r=cnt+2;r<=n;)
	{
		if(ma>=(n-l+1))
		{
			break;
		}
		if(sum-(a[l]-a[r])>=0)
		{
			sum-=a[l]-a[r];
			cnt++;
			r++;
			ma=max(ma,cnt);	
		}
		else
		{
			cnt--;
			sum+=(a[l]-a[l+1])*cnt;
			l++;
		}
	}
	cout<<ma<<"\n";
	return 0;
}
/*
100pts双指针做法 
*/
