#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long p=0,ans=0;
void dfs(long long now,int choos,int k)
{
	if(choos==m||k>n)
	{
		if(choos==m)
			ans=max(ans,now);
		return;
	}
	dfs(now&a[k],choos+1,k+1);
	dfs(now,choos,k+1);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(m==n)
        {
        	if(p==0) p=a[i];
        	else p&=a[i];
		}
    }
    if(m==n)
    {
    	cout<<p;
    	return 0;
	}
	for(int i=1;i<=n;i++)
		dfs(a[i],0,i);
	cout<<ans;
    return 0;
}
