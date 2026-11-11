#include <bits/stdc++.h>
using namespace std;
long long sum,n,ans,f,l,bb,cc;
struct st{
	long long s1;
	char s2;
}a[200105];
struct st2{
	long long s1;
	char s2;
}b[200105];
struct st3{
	long long s1;
	char s2;
}c[200105];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i].s1>>a[i].s2;
		sum+=a[i].s1;
	}
	if(sum%2==1)
	{
		f=1;
	}
	sum/=2;
	long long i=1;
	l=sum;
	while(l!=0)
	{
		if(l>=a[i].s1)
		{
			l-=a[i].s1;
			b[i].s1=a[i].s1;
			b[i].s2=a[i].s2;
			i++;
		}
		else
		{
			b[i].s1=l;
			b[i].s2=a[i].s2;
			a[i].s1-=l;
			l=0;
		}
	}
	long long k=i;
	for(long long j=1;j<=n-k+1;j++)
	{
		c[j].s1=a[i].s1;
		c[j].s2=a[i].s2;
		i++;
	}
	if(f==1)
	{
		c[1].s1--;
	}
//	for(long long i=1;i<=k;i++)
//	{
//		cout<<b[i].s1<<" "<<b[i].s2<<" ";
//	}
//	cout<<"\n";
//	for(long long i=1;i<=n-k+1;i++)
//	{
//		cout<<c[i].s1<<" "<<c[i].s2<<" ";
//	}
	long long len=n-k+1,bb=1;
	long long cc=len;
	while(bb<=k && cc>=1)
	{
		if(b[bb].s2==c[cc].s2)
		{
			if(b[bb].s1>c[cc].s1)
			{
				b[bb].s1-=c[cc].s1;
				cc--;
			}
			else if(b[bb].s1==c[cc].s1)
			{
				cc--;
				bb++;
			}
			else
			{
				c[cc].s1-=b[bb].s1;
				bb++;
			}
		}
		else
		{
			if(b[bb].s1>c[cc].s1)
			{
				ans+=c[cc].s1;
				b[bb].s1-=c[cc].s1;
				cc--;
			}
			else if(b[bb].s1==c[cc].s1)
			{
				ans+=c[cc].s1;
				cc--;
				bb++;
			}
			else
			{
				ans+=b[bb].s1;
				c[cc].s1-=b[bb].s1;
				bb++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
