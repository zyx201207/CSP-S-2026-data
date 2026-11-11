#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[200010],b[3010],c[3010];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n<=500)
    {
        for(int i=1;i<=n;i++)
        {
            memset(c,0,sizeof(c));
            int u=1;
            for(int j=i;j<=n;j++)
            {
                bool op=false;
                for(int k=j+1;k<=n;k++)
                {
                    if(a[k]==a[j])
                    {
                        c[u]=a[k];
                        u++;
                        j=k;
                        op=true;
                        break;
                    }
                }
                if(!op)
                {
                    c[u]=a[j];
                    u++;
                }
                //cout<<op<<" ";
            }
            for(int i=1;i<=u-1;i++)
            {
                b[c[i]]++;
                //cout<<c[i]<<" ";
            }
            //cout<<endl;
        }
        for(int i=1;i<=m;i++)
        {
            cout<<b[i]<<" ";
        }
    }
    return 0;
}
