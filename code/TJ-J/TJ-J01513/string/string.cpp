#include<bits/stdc++.h>
using namespace std;
int n,a[300000],l=1,r;
long long cnt,num;
char c[300000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		num+=a[i];
	}
	num/=2;
	r=n;
	while(l<r)
	{
		if(c[l]==c[r])
		{
			cnt+=min(a[l],a[r]);
		}
		if(a[l]>a[r])
		{
			a[l]-=a[r];
			--r;
		}
		else if(a[l]<a[r])
		{
			a[r]-=a[l];
			++l;
		}
		else
		{
			++l;
			++r;
		}
	}
	cout<<(num-cnt)<<endl;
	return 0;
}
