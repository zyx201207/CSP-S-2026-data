#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n;
int a[N];
char ch[N];
int l,r;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>ch[i];
	}
	int l=1,r=n;
	while(l<r)
	{
		if(ch[l]!=ch[r])
		{
			ans+=min(a[l],a[r]);
		}
		if(a[l]<a[r])
		{
			a[r]-=a[l];
			a[l]=0;
			l++;
		}
		else if(a[l]==a[r])
		{
			a[l]=a[r]=0;
			l++,r--;
		}
		else
		{
			a[l]-=a[r];
			a[r]=0;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
