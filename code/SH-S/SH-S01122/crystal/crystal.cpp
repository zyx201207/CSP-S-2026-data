#include <bits/stdc++.h>
using namespace std;
long long m,n;
long long crystal[500005];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long num=0;
	for(long long i=0;i<n;i++) cin>>crystal[i];
	sort(crystal,crystal+n,less<long long>());
	if(n%2==0) num=n/2;
	else num=n/2+1;
	long long dsum=0;
	for(long long i=0;i<num;i++)
	{
		dsum+=crystal[num-1]-crystal[i];
	}
	long long ans=num;
	int same=0;
	int nm=num;
	while(crystal[nm-1]==crystal[nm])
	{
		same++;
		nm++;
	}
	nm=num; 
	while(crystal[nm-1]==crystal[nm-2])
	{
		same++;
		nm--;
	}
	ans+=same;
	if(dsum>m)
	{
		long long cnt=0;
		while(dsum>m)
		{
			dsum-=crystal[cnt];
			ans--;
			cnt++;
		}
		ans++;
	}
	if(dsum<m)
	{
		long long cnt=num+same;
		while(dsum<m)
		{
			dsum+=crystal[cnt]-crystal[num-1];
			ans++;
			cnt++;
		}
		ans--;
	}
	cout<<ans<<endl;
	return 0;
}
