#include <bits/stdc++.h>
using namespace std;
const int N=2e6+100;
int main()
{
	freopen("migrate.in","r",stdin);	
	freopen("migrate.out","w",stdout);	
    int c,t;
    cin>>c>>t;
    while (t--)
    {
    	memset(a,0,sizeof a);
    	int n,d;
    	cin>>n>>d;
    	for (int i=1;i<=n;i++)
    		cin>>a[i];
    	if (n<=3) cout<<0<<"\n",continue;
    	int cnt=0;
    	for (int i=1;i<n;i++)
    	{
    		for (int j=i+1;j<=n;j++)
    		{
    			if (a[j]-a[i]<=d)
    			    continue;
    			cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
