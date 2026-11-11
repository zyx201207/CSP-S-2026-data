#include<bits/stdc++.h>

using namespace std;

const int P=998244353;
const int N=1e6+10,M=2e6+10;

long long a[N],n;
char c[N];
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<=r)
	{
		if(c[l]!=c[r])
		{
			ans+=min(a[l],a[r]);
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r])
			{
				a[r]-=a[l];
				l++;
			}
			else if(a[l]==a[r])
			{
				l++,r--;
			}
		}
		if(c[l]==c[r])
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r])
			{
				a[r]-=a[l];
				l++;
			}
			else if(a[l]==a[r])
			{
				l++,r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c
*/

/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

