#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,cnt;
int a[N],b[N],c[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    bool f=0;
    for(int i=1;i<n;i++)
        if(a[i]>a[i+1])
            f=1;
    if(!f)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                int t=lower_bound(b+1,b+1+cnt,a[j])-b;
                if(b[t]==a[j]) cnt=t-1;
                b[++cnt]=a[j];
            }
            for(int j=1;j<=cnt;j++) cout<<b[j]<<" ";
            cout<<endl;
            cnt=0;
        }
        for(int i=1;i<=m;i++) cout<<c[i]<<" ";
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            for(int k=1;k<=cnt;k++)
            {
                if(b[k]==a[j])
                {
                    cnt=k-1;
                    break;
                }
            }
            b[++cnt]=a[j];
        }
        for(int j=1;j<=cnt;j++) c[b[j]]++;
        cnt=0;
    }
    for(int i=1;i<=m;i++) cout<<c[i]<<" ";
    return 0;
}
