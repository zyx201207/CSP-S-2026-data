#include<bits/stdc++.h>
using namespace std;
long long n,sum,ans=0;
const long long N=2*1e5+3;
struct act{
	long long ber;
	char ch;
}a[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(NULL);
	cin>>n;
	long long x=0;
	char t=' ';
	while(n--)
	{
		long long y;
		char z;
		cin>>y>>z;
		if(t!=z)
		{
		a[++x].ber=y;
		a[x].ch=z;
		}
		else 
		{
			a[x-1].ber+=y;
			t=z;
		}
		sum+=y;
	}
	sum/=2;
	long long i=1,j=x;
	while(sum)
	{
		long long w=0;
		char v=a[i].ch;
		if(sum>=a[i].ber)
		{
			sum-=a[i].ber;
			w=a[i].ber;
			a[i].ber=0;
			i++;
		}
		else
		{
			a[i].ber-=sum;
			w=sum;
			sum=0;
		}
		while(w)
		{
			long long p=a[j].ber;
			char q=a[j].ch;
			if(w>=p)
			{
				if(q==v) w-=p;
				else{
					ans+=p;
					w-=p;
				}
				a[j].ber=0;
				j--;
				continue;
			}
			else
			{
				if(q==v) p-=w;
				else{
					ans+=w;
					p-=w;
				}
				w=0;
				continue;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
