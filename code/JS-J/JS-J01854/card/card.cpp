#include <bits/stdc++.h>
using namespace std;
int a[300010];
int cnt[300010];
int ans[300010];
int y[300010];
int n,m;
int k;
void check(int x)
{
    for(int i=1;i<=m;i++)
    {
        ans[i]=0;
        y[i]=0;
    }
    for(int i=x;i<=n;i++)
    {
          ans[a[i]]++;

          if(ans[a[i]]>1)
          {

              for(int j=y[a[i]];j<i;j++)
              {
                  ans[a[j]]--;
              }
          }

          y[a[i]]=i;
    }
    for(int i=1;i<=m;i++)
    {
        if(ans[i]==1)
        {
            cnt[i]++;
        }
    }
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        check(i);
    }
    for(int i=1;i<=m;i++)
    {
        cout<<cnt[i]<<" ";
    }
    return 0;
}
