#include<bits/stdc++.h>
using namespace std;
int n,a[200000],m,maxn,t=1,tmax,tc[200000];
bool vis[200000]={0};
long long dfs(int h)
{
	if(h==m)
	{
	
    	if(tmax>=maxn)
    	{
        	maxn=tmax;
    	}
    	return 0;
	}
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
        	vis[i]=1;
        	
            tc[h]=tmax;
            tmax&=a[i];
            dfs(h+1);
            tmax=tc[h];
            vis[i]=0;
        }
    }
    return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        tmax=a[i];
        vis[i]=1;
        dfs(1);
        vis[i]=0;
    }
    cout<<maxn<<'\n';
    return 0;
}
