#include<bits/stdc++.h>
using namespace std;
int n,m;
int t[100005];
int a[100005];
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
        int pos=0;
        for(int i=q;i<=n;i++)
        {
            pos=i;
            for(int j=i+1;j<=n;j++)
            {
                if(a[i]==a[j])
                {
                    pos=j;
                }
            }
            i=pos;
        }
        for(int i=pos;i<=n;i++)
        {

            t[a[i]]++;
        }

    }
    for(int i=1;i<=m;i++)
    {

        cout<<t[i]<<" ";
    }
    return 0;
}
