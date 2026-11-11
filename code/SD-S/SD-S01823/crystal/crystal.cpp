#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int N=5*1e5+5;
long long a[N];long long b[N],maxn=-1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	int n,i;bool fl=1,fll=1;unsigned long long m;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
	{
		b[i]=a[i]-a[i-1];if(a[i]!=i) fl=0;
		if(b[i]!=b[i-1]&&i>2) fll=0;
	}
	b[1]=0;
	if(fl==1)
	{
		long long f=1;
		for(i=1;i<=n;i++)
		{
			m-=i;if(m<0)
			break;f++;
		}
		cout<<f;return 0;
	}
	if(fll==1)
	{
		long long f=1;int ans=b[n];
		for(i=1;i<=n;i++)
		{
			m-=i*ans;if(m<0)
			break;f++;
		}
		cout<<f;return 0;
	}
	for(i=1;i<=n;i++)
	{
		int f=1,mm=m;
		long long ans=0;
		for(int j=i;j>=1;j--)
		{
			mm-=b[j]+ans;
			if(mm<0)
			break;
			//cout<<m<<" "<<i<<" "<<endl;
			f++;ans+=b[j];
		}//cout<<"to now"<<endl;
		if(f>maxn)
		maxn=f;
	}
	cout<<maxn;
	return 0;
}
