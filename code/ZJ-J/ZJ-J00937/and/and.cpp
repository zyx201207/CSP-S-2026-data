#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200020],p[200020][35],s[200020],t[200020],len,cnt,ans;
void fun(long long val,long long pos)
{
	long long len=0;
	while(val)
	{
		p[pos][++len]=val%2;
		val/=2;
	}
}
long long ksm(long long x,long long y)
{
	long long sum=1;
	while(y)
	{
		if(y%2==1)
		{
			sum*=x;
		}
		x*=x;
		y/=2;
	}
	return sum;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		fun(a[i],i);
	}
	for(long long pos=30;pos>=1;pos--)
	{
		if(pos==30)
		{
			cnt=0;
			for(long long i=1;i<=n;i++)
			{
				if(p[i][pos]==1)
				{
					cnt++;
				}
			}
			if(cnt>=m)
			{
				for(long long i=1;i<=n;i++)
				{
					if(p[i][pos]==1)
					{
						s[++len]=i;
					}
				}
				ans+=ksm(2,pos-1);
			//	cout<<pos<<endl;
			}
			else
			{
				for(long long i=1;i<=n;i++)
				{
					s[++len]=i;
				}
			}
		}
		else
		{
			cnt=0;
			for(long long i=1;i<=len;i++)
			{
				if(p[s[i]][pos]==1)
				{
					cnt++;
				}
			}
			if(cnt>=m)
			{
				long long newlen=0;
				for(long long i=1;i<=len;i++)
				{
					if(p[s[i]][pos]==1)
					{
						t[++newlen]=s[i];
					}
				}
				for(long long i=1;i<=newlen;i++)
				{
					s[i]=t[i];
				}
				len=newlen;
				ans+=ksm(2,pos-1);
			//	cout<<pos<<endl;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
//4 2
//3 15 12 12

//5 3
//31 3 1 15 7