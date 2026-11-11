#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
long long n,a[N],l=1,r,ans=0;
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	r=n;
	if(n==1)
	{
		cout<<"0";
		return 0;
	}
	int f=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		if(c[i]!=c[i-1])
			f=1;
	}
	if(f==0)
	{
		cout<<"0";
		return 0;
	}
	while(l<r)
	{
		if(a[l]>=a[r]&&c[l]!=c[r])
		{
			a[l]-=a[r];
			ans+=a[r];
			r--;
		}
		else if(a[l]<a[r]&&c[l]!=c[r])
		{
			a[r]-=a[l];
			ans+=a[l];
			l++;
		}
		else if(c[l]==c[r])
		{
			if(a[l]>=a[r])
			{
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r])
			{
				a[r]-=a[l];
				l++;
			}
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//6
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b
