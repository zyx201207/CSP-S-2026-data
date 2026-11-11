#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n,m;
int a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=-1;
	for(int i=1;i<=n;i++)
	{
		int mx=-1;
		for(int j=i+1;j<=n;j++)
		{
		    int num=a[i]^a[j];
			if(num>=mx)
			{
			   mx=num;	
			}	
		}
		if(mx>=ans)
		ans=mx;
	}
	cout<<ans;
return 0;
}
