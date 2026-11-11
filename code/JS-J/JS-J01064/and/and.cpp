#include<bits/stdc++.h>
using namespace std;
int ans=-1e9;
void dfs(int a[],int n,int m,int ith,int val,int pre)
{
    if(ith==m)
    {
        ans=max(ans,val);
        return;
    }
    for(int i=pre+1;i<=n-m+ith;i++)
    {
        int t=val;
        val=(val&a[i]);
        dfs(a,n,m,ith+1,val,i);
        val=t;
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,m; cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    if(m==1)
    {
        cout<<*max_element(a,a+n);
        return 0;
    }
    for(int i=0;i<=n-m;i++)
        dfs(a,n,m,1,a[i],i);
    cout<<ans;
    return 0;
}
