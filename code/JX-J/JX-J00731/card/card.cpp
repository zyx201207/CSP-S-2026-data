#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,card[500005],chang[500005],a[300005];
    cin>>n>>m;
    for(int i=1;i<=m;i++) a[i]=0;
    for(int i=1;i<=n;i++) cin>>card[i];
    for(int i=1;i<=n;i++)
    {
        int cnumber=0;
        for(int j=i;j<=n;j++)
        {
            cnumber++;
            for(int t=1;t<=cnumber;t++)
            {
                if(chang[t]==card[j])
                {
                    for(int k=t;k<cnumber;k++) chang[k]=0;
                    cnumber=t;
                    break;
                }
            }
            chang[cnumber]=card[j];
        }
        for(int j=1;j<=cnumber;j++) a[chang[j]]++;
        for(int j=1;j<=cnumber;j++) chang[j]=0;
    }
    for(int i=1;i<=m;i++) cout<<a[i]<<" ";
    return 0;
}
