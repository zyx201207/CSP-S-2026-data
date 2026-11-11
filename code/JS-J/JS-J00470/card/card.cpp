#include<bits/stdc++.h>
using namespace std;
struct Node{
    int next;
    int jump;
    int x;
}a[500005];
int t[300005];
int ans[300005];
bool f[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i].x;
    for(int i=n;i>=1;i--)
    {
        if(i!=n)
            a[i].next=i+1;
        else
            a[i].next=n;
        if(t[a[i].x]!=0)
            a[i].jump=t[a[i].x];
        if(t[a[i].x]==0)
            t[a[i].x]=i;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            f[j]=false;
        int u=i;
        while(a[u].next!=u)
        {
            f[a[u].x]=true;
            if(a[u].jump!=0)
                u=a[u].jump;
            else
                u=a[u].next;
        }
        f[a[u].x]=true;
        for(int j=1;j<=m;j++)
            if(f[j])
                ans[j]++;
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}