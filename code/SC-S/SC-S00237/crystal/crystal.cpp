#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+1;
long long a[MAXN];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long c=a[2]-a[1];
	m/=c;
	long long sum=0,i=0;
	while(m>=0)
	{
		i++;
		sum++;
		m-=i;
	}
	cout<<sum;
	return 0;
}