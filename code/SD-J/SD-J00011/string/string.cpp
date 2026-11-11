#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
#include<string>
using namespace std;
const int N=2e5+5;
inline int read()
{
	int f=1,x=0;
	char ch;
	ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
void write(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
long long a[N],ans;
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		cin>>c[i];
	}
	int l=1,r=n;
	while(l<r)
	{
		if(c[l]==c[r])
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				r--;
			}
			else if(a[l]==a[r])
			{
				l++;
				r--;
			}
			else
			{
				a[r]-=a[l];
				l++;
			}
		}
		else
		{
			if(a[l]>a[r])
			{
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
			else if(a[l]==a[r])
			{
				ans+=a[l];
				l++;
				r--;
			}
			else
			{
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
