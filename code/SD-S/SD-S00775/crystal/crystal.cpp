#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long ans=2e18,cnt=1;
long long a[500005],he[500005];
bool check(long long l,long long r)
{
	ans=a[r]*(r-l+1)-(he[r]-he[l-1]);
	return ans<=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		he[i]=he[i-1]+a[i];
	}
	for(int l=1;l<=n;l++)
	{
		long long le=l,ri=n,r;
		while(le<=ri)
		{
			r=(le+ri)/2;
			if(check(l,r))
			{
				le=r+1;
				cnt=max(cnt,(long long)r-l+1);
			}
			else
			{
				ri=r-1;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
 } 
