#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[200020];
char c[200020];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	while(l<r)
	{
		if(c[l]==c[r])
		{
			long long tmp=min(a[l],a[r]);
			a[l]-=tmp;
			a[r]-=tmp;
			if(a[l]==0) l++;
			if(a[r]==0) r--;
		}
		else
		{
			long long tmp=min(a[l],a[r]);
			ans+=tmp;
			a[l]-=tmp;
			a[r]-=tmp;
			if(a[l]==0) l++;
			if(a[r]==0) r--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
//3
//2 a
//2 b
//1 c

//2
//2 a
//3 a

//6
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b