#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long int n,m,a[N],cnt[N];
char b[1010][1010],ans[1010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int t=a[i],q=1,x=1,cnt=1;
		while(t>0)
		{
			q=t%2;
			b[i][cnt]=q*x+'0';
			cnt++;
			x*=10;
			t/=2;
		}
		cnt1[i]=cnt;
	}
	sort(a+1,a+n+1);
	if(m==1)
	{
		cout<<a[n];
		return 0;
	}else
	{
		for(int i=1;i<=min(cnt[n],cnt[]))	
	}
	for(int i=n-1;i>=n-m;i--)
	{
		ans=ans^b[i];
	}
	cout<<ans;
	return 0;
}