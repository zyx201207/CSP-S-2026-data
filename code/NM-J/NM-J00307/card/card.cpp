#include <bits/stdc++.h>
using namespace std;
int a[100005],ans[100005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ans[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        if(ans[a[i]]>=1)
        {
            for(int j=1;j<=i;j++)
            {
                a[j]=-1;
                ans[a[1]]=0;
            }
        }
        ans[i]+=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==-1)
        {

        }
        else{
            cout<<a[i];
        }
    }
    return 0;
}
