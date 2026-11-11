#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen(and.in,"r",stdin);
    freopen(and.out,"w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n];
    int b[n];
    queue que();
    int k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
   for(int i=1;i<=m;i++)
    {
        que.push(a[i]);
        b[i]+=1;
        k=a[1];
        if(a[i+1]==k)
        {
            que.pop(a[1],a[i]);
            for(int j=i+1;j<=n;j++)
            {
                b[i]+=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
      cout<<b[i];
    }


    return 0;
}
