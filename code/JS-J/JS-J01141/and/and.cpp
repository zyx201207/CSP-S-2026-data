#include<bits/stdc++.h>
using namespace std;
int n,m,dp[200005],a[200005],cun[200005][35],mo[35];
vector< int > v[35];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    mo[1]=1;
    for(int i=2;i<=30;i++)
    {
        mo[i]=mo[i-1]*2;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=30;j++)
        {
            if((a[i]&mo[j])==mo[j])
            {
                v[j].push_back(a[i]);
            }
        }
    }
    int wei=0;
    for(int i=30;i>=1;i--)
    {
        if(v[i].size()>=m)
        {
            wei=max(wei,i);
        }
    }
    //cout<<wei;
    int num=0;
    memset(a,0,sizeof(a));
    if(wei==0)
    {
        cout<<0;
        return 0;
    }
    for(int i=0;i<v[wei].size();i++)
    {
        num++;
        a[i+1]=v[wei][i];
    }
    sort(a+1,a+num+1);
    for(int i=1;i<=num;i++)
    {
        dp[0]=a[i];
        for(int j=min(i,m);j>=1;j--)
        {
            dp[j]=max(dp[j-1]&a[i],dp[j]);
        }
    }
    cout<<dp[m];
    return 0;
}
