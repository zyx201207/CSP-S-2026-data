#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],aa[N],b[505];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    bool A=1,B=1;
    for (int i=1;i<=n;i++)
       cin>>a[i],aa[i]=a[i]+100,b[aa[i]]++;
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    	if (a[i]!=i) A=0;
    int cha=a[2]-a[1]; 
    for (int i=2;i<=n;i++)
    	if (a[i]-a[i-1]!=cha) B=0;
    int maxx=1;
    if (A)
    {
    	for (int i=1;i<=n;i++)
    	{
    		if (i*(i-1)/2>m)
    		{
    			maxx=i-1;
    			break;
			}
		}
		cout<<maxx;
		return 0;
	}
	if (B)
	{
		for (int i=1;i<=n;i++)
    	{
    		if (i*(i-1)*cha/2>m)
    		{
    			maxx=i-1;
    			break;
			}
		}
		cout<<maxx;
		return 0;
	}
    if (a[n]<=100)
    {
    	for (int i=0;i<=200;i++)
    	{
    		int sum=0,cnt=b[i];
    		for (int j=i-1;j>=1;j--)
    		{
    			if (b[j])
    			{
    				if ((i-j)*b[j]+sum<=m)
    				    sum+=(i-j)*b[j],cnt+=b[j];
    				else
    				    cnt+= (m-sum)/(i-j);
				}
			}
			maxx=max(cnt,maxx);
		}
		cout<<maxx;
		return 0;
	}
    for (int i=2;i<=n;i++)
    {
    	int sum=0,cnt=1;
    	for (int j=i-1;j>=1;j--)
    	{
    		int k=a[i]-a[j];
    		if (sum+k<=m)
    		   sum+=k,cnt++;
    		else break;
		}
		maxx=max(cnt,maxx);
	}
	cout<<maxx;
	return 0;
} 
