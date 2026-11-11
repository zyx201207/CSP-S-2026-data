#include<bits/stdc++.h>
using namespace std;
const int MAX=5E5+005;
long long a[MAX],maxv=0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		int cnt=1,temp=m;
		for(int j=i-1;j>=1;j--)
		{
			if(a[i]-a[j]<=temp)
			{
				temp-=a[i];
				temp+=a[j];
				cnt++;
			}
			else break;
		}
		if(cnt>maxv)maxv=cnt;
	}
	cout<<maxv;
	return 0;
}