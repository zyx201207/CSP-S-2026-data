#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long n,m;
long long a[N],t,ans;
long long s;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	stable_sort(a+1,a+n+1);
	for(int k=1;k<=n-m+1;k++)
	{
		s=a[k];
		for(int i=k+1;i<k+m;i++)
		{
			s=a[i]&s;
			if(s>ans)
			{
				ans=s;
			}
		}
	}
	cout<<ans;
	return 0;
}
