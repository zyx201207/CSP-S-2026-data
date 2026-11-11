#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],b[N],c[N];
long long n,m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long maxa=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	sort(a+1,a+n+1);
	long long len=1;
	b[1]=a[1];c[len]++;
	for(int i=2;i<=n;i++)
	{
		if(b[len]!=a[i])
		{
			b[len+1]=a[i];
			len++;
		}
		c[len]++;
	}
	if(len==1)
	{
		cout<<n<<endl;
		return 0;
	}
	long long ans=0;
	for(long long now=1;now<=maxa;now++)
	{
		long long w=upper_bound(b+1,b+len+1,now)-b-1;
		long long sum=0,m1=m;
		do
		{
			if(((now-b[w])*c[w])<=m1)
			{
				sum+=c[w];
				m1-=((now-b[w])*c[w]);
			}
			else
			{
				sum+=(m1/(now-b[w]));
				m1=0;
			}
			w--;
		}while(m1>0&&w>0);
		ans=max(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}
