#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2000005;
int c,t,n,d;
int x[maxn];
vector<int>ans;
int ans1=0;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans1=0;
		cin>>n>>d;
	    for(int i=1;i<=n;i++)
	    {
	    	cin>>x[i];
	    	for(int j=1;j<=i-3;j++)
	    	{
	    		int can=0;
	    		for(int h=j;h<i;h++)
	    		{
	    			if(x[i]-x[h]<=d)
	    			{
	    				can++;
					}
				}
				if(can==2)
				{
					ans1++;
				}
			}
		}
		ans.push_back(ans1);
	}
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<"\n";
	}
	return 0;
}
