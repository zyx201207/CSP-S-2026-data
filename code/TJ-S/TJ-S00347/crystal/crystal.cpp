#include <bits/stdc++.h>
#define int long long
using namespace std;
int arr[500005];
int q[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		q[i]=q[i-1]+(arr[i]-arr[i-1])*(i-1);
	} 
	sort(arr+1,arr+n+1);
	int ans;
	for(int i=1;i<=n;i++)
	{
		if(q[i]<=m) ans=i;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

