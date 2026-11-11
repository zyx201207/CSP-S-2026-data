#include<bits/stdc++.h>

using namespace std;
int c,T,n,k,u[1000001],v[1000001],ans,f[1001][1001],a[1001];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--)
    {
    	if(c<=7)
    	{
	    	for(int i=1;i<=n;i++)
	    	{
	    		for(int j=i;j<=n;j++)
	    		{
	    			f[i][j]=f[j][i]=0;
				}
				a[i]=0;
			}
		}
    	cin>>n>>k;
    	for(int i=1;i<=n-1;i++)
    	{
    		cin>>u[i]>>v[i];
		}
		if(n==k)
		{
			cout<<0<<'\n';
			continue;
		}
		if(c<=7)
		{
			for(int i=1;i<=n-1;i++)
	    	{
	    		cin>>u[i]>>v[i];
	    		f[u[i]][v[i]]=f[v[i]][u[i]]=1;
	    		for(int j=1;j<=n;j++)
	    		{
	    			if(f[u[i]][j]!=0)
	    				f[v[i]][j]=f[j][v[i]]=min(f[v[i]][j],f[u[i]][j]+1);
	    			if(f[v[i]][j]!=0)
	    				f[u[i]][j]=f[j][u[i]]=min(f[u[i]][j],f[v[i]][j]+1);
				}
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					a[i]=max(f[i][j],a[i]);
				}
			}
			sort(a+1,a+n);
			cout<<max(a[n],a[n-1])<<'\n';
			continue;
		}
		if(c==13||c==14)
		{
			ans=(n+1)/2-k+2;
			if(ans<=3)
			{
				cout<<1<<'\n';
				continue;
			}
			if(k==1)
			{
				cout<<ans/2<<'\n';
				continue; 
			}
			cout<<(ans+3)/2<<'\n';
		}
	}
    return 0;
}

