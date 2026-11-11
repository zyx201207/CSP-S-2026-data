//SN-J00793
//张意添
//西安交通大学附属中学
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
char c[N];
long long n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n,ans=0;
	while(l<=r)
	{
		long long cha=abs(a[l]-a[r]);
		if(c[l]!=c[r])
		{
			ans+=min(a[l],a[r]);
		}
		if(a[l]>a[r])
		{
			a[l]=cha;r--;
		}
		else if(a[l]<a[r])
		{
			a[r]=cha;l++;
		}
		else
		{
			l++;r--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
