#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200005];
int a1[200005];
bool b[200005]={false};
void dfs(int dep)
{
	if(dep>m)
	{
		int ans1=a1[1];
		for(int i=2;i<=m;i++)
		{
		    ans1=(ans1&a1[i]);	
		}
		ans=max(ans,ans1);
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i])
		{
		    continue;	
		}
		a1[dep]=a[i];	
		b[i]=true;
		dfs(dep+1);
		b[i]=false;
	}
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
	}
	dfs(1);
    cout<<ans<<'\n';
    
   
	
    return 0;	
}


