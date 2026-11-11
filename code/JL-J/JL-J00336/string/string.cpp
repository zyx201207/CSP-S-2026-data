#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N];
long long sum,ans;
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	int i=1,j=n;
	while(i<j&&sum>1)
	{
		if(c[i]!=c[j])
			ans+=min(a[i],a[j]);
		if(a[i]>a[j])
		{
			sum-=a[j];
			a[i]-=a[j];
			j--;
		}
		else
		{
			sum-=a[i];
			a[j]-=a[i];
			i++;
		}
	}
	cout<<ans;
	return 0;
}