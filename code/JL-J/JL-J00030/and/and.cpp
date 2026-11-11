#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out""w",stdout);
    int n,m;
    cin>>n>>m;
    int maxn=0,cnt=0;
    int a[200005];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            maxn=max(maxn,a[i]&a[j]);
        }
    }
    if(m>2)
    {
        for(int i=1;i<=m-2;i++)
        {
            cnt=max(cnt,maxn&a[i]);
        }
        cnt=cnt/2;
    }
    else
    {

        cnt=maxn;
    }
    cout<<cnt;
    return 0;
}
