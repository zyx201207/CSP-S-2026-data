#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
int n,b[N];
long long m,a[N],ans,max1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=n-1;i>0;i--)
	{
		ans=1;
		int j=1,m1=m;
		while(m1)
		{
			if(i-j<0) break;
			if(m1-(a[i]-a[i-j])>=0)
			{
				m1-=a[i]-a[i-j];
				ans++;
				j++;
			}
			else break;
		}
		if(ans>max1) max1=ans;
	}
	printf("%lld",max1);
	return 0;
}
