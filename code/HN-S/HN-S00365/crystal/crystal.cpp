#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500101];
long long sum=0;
long long cnt;
long long cnt1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cin.tie(0);
	cin>>n>>m;
	long long m2=m*1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
//	cout<<sum<<endl;
	sum/=n;
//	cout<<sum;
	int ff=0;
	sort(a+1,a+n+1);
//	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>sum)
		{
			ff=i-1;
			break;
		}
	}
	for(int i=ff;i>=1;i--)
	{
		m-=(sum-a[i]);
		if(m<0)
		{
			break;
		}
		cnt++;
	}
	sum++;
	ff=0;
//	cout<<"sum="<<sum<<endl;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>sum)
		{
			ff=i-1;
			break;
		}
	}
//	cout<<"ff="<<ff<<endl;
	for(int i=ff;i>=1;i--)
	{
		m2-=(sum-a[i]);
		if(m<0)
		{
			break;
		}
		cnt1++;
	}
//	cout<<cnt1<<endl;
	cout<<max(cnt,cnt1);
	return 0;
}

/*

5 8
-3 -1 2 2 7

4
*/
