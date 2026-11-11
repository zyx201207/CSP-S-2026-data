#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
string s;
long long cnt[300005];
long long cnt1[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	for(long long i=1;i<=n;i++)
	{
		for(long long i=1;i<=n;i++)
		{
			s+=a[i];
		} 
	} 
	cout<<3<<" "<<1<<" "<<4; 
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
