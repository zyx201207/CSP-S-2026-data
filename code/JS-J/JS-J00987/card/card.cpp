#include <bits/stdc++.h>
using namespace std;
int a[200005];
int box[3005];
int f[200005];
int b[3005];
int w[3005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    int t=n;
    int i=1;
    while(t--)
    {
        memset(b,0,sizeof(b));
        memset(w,0,sizeof(w));
        for(int j=i;j<=n;j++)
        {
            if(b[a[j]])
            {
                for(int z=w[a[j]];z<j;z++)
                {
                    b[a[z]]=0;
                    w[a[z]]=0;
                    f[z]=0;
                }
            }
            b[a[j]]=1;
            w[a[j]]=j;
            f[j]=a[j];

        }
        for(int j=i;j<=n;j++)
        {
            if(f[j]) box[f[j]]++;
        }
        i++;
    }
    for(int i=1;i<=m;i++) cout<<box[i]<<" ";
    return 0;
}
