#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int ans[1000005],d[1000005],a[1000005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

    }
    for(int qq=1;qq<=n;qq++)
    {
        for(int i=qq;i<=n;i++)
        {
            if(d[a[i]]==0)//3 1 2 1 3 2 3 1 2 1
            {
                d[a[i]]++;//3 1
            }
            else
            {
                int j=i-1;
                while(a[j]!=a[i])
                {
                    d[a[j]]=0;
                    j--;
                }
                d[a[i]]=1;
            }
        }
        for(int k=1;k<=m;k++)
        {
            if(d[k]==1)
            {
                ans[k]++;
                d[k]=0;
            }
        }
    }
    for(int k=1;k<=m;k++)
    {
        cout<<ans[k]<<" ";
    }
    return 0;
}
