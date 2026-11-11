#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int n,m;
int a[500005],d[500005];
int maxn=0;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        d[i]=a[n]-a[i];
    }
    for(int i=n;i>=1;i--)
    {
        int cnt=0,ans=0;
        for(int j=i;j>=1;j--)
        {
            cnt+=d[j]-d[i];
            if(cnt>m)
            {
                break;
            }
            ans++;
        }
        maxn=max(ans,maxn);
    }
    cout<<maxn<<endl;
    return 0;
}

