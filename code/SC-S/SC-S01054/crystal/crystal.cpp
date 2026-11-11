#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m;
long long a[N],s[N];
long long b;
long long q=1;
long long z=-1,I;
int main()
{
	//ios::sync_with_stdio(),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		b=a[i]-a[i-1];
		s[i]=s[i-1]+(i-1)*b;
	}
//	for(int i=1;i<=n;i++)
//	{
//		cout<<s[i]<<" ";
//	}
//	cout<<'\n';
	for(int i=1;i<=n;i++)
	{
		I=i;
		if(s[i]>m)
		{
			long long l=q,r=i;
			while(l<=r)
			{
				long long mid=(l+r)/2;
				if(s[i]-s[mid]<=m)
				{
					r=mid-1;
				}
				else
				{
					l=mid+1;
				}
			}
			//cout<<s[i]<<" "<<s[l]<<"\n"; 
			//cout<<s[i]<<" "<<s[l]<<'\n';
			q=l;
			z=max(z,i-l);
		}
		else
		{
			z=max(z,I);
		}
	}
	cout<<z;
}