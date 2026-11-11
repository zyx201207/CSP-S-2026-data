#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],t[300005],l=1,t2[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int q=1;q<=n;q++)
    {
        for(int i=q;i<=n;i++)
        {
            t[a[i]]++;
            if(t[a[i]]>1)
            {
                for(int j=l-1;j>=1;j--)
                {

                    if(b[j]==a[i])
                    {
                        l=j;
                        t[b[j]]--;
                        break;
                    }
                    t[b[j]]--;
                }
            }
            b[l++]=a[i];
        }
        for(int i=1;i<l;i++)
        {
            t2[b[i]]++;
        }
        l=1;
        memset(t,0,sizeof(t));
    }
    for(int i=1;i<=m;i++)
    {
        cout<<t2[i]<<" ";
    }
    return 0;
}
