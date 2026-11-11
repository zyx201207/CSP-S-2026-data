#include<bits/stdc++.h>
using namespace std;
long long n,m,arr[5000005],sum,sum1,brr[5000005],ans1=1e5,ans2=1e5;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>n>>m;
	while(m--)
	{
		cin>>sum>>sum1;
		sum--;
		for(int i=1;i<=sum;i++)
		{
			cin>>arr[i]>>brr[i];
			ans1=min(ans1,arr[i]);
			ans2=min(ans2,brr[i]);
		}
	}
	cout<<ans1<<'\n'<<ans2;
	return 0;
}