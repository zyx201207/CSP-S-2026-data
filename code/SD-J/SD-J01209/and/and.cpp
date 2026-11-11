#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
bool book[200005];
bool u[200005];
int w[200005];
int ua=1;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,k,ans=2147483647;
	map<int,int>mp;
	map<int,int>nums;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		nums[a[i]]++;
	}
	int p=31;int num=0;
	while(p>-1)
	{
		
		int cnt=0;
		for(int i=0;i<n;i++)if(book[i]==0)w[i]=((a[i]>>p)&1),cnt+=w[i];else w[i]=0;
		if(cnt>=k)
		{
			for(int i=0;i<n;i++)
			{
				if(book[i]==0&&w[i]==1)mp[i]++;
				else book[i]=1;
			}
			
		}
		p--;
	}
	for(auto v : mp)
	{
		if(u[v.first]==0&&book[v.first]==0)
		{
			ans&=a[v.first];
			num+=nums[a[v.first]];
			u[v.first]=1;
		}
//		cout<<a[v.first]<<' ';
		if(num>=k)break;
	}
	cout<<ans;
	return 0;
}
/*

4 2
3 15 12 12


5 3
31 3 1 15 7

262142 262143 262144 
*/

