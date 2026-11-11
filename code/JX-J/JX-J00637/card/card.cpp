#include<bits/stdc++.h>
using namespace std;
int t[500000],jg[500000];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,b[1000000],c[1000000],f=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    for(int i=1;i<=n;i++)
    {
        f=1;
        for(int d=1;d<=n;d++)
        {
            c[d]=0;
            t[d]=0;
        }
        if(t[b[i]]<1)
        {t[b[i]]++;
            c[f]=b[i];
            f++;
        }
        else
        {
            for(int j=i-1;j>0;j--)
            {
                if(b[i]==b[j])
                {
                    f=j;
                    c[f]=b[j];
                    f++;
                }
            }
        }
        for(int j=1;j<f;j++)
        {
            for(int r=1;r<=m;r++)
            {
                if(c[j]==r) jg[r]++;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<jg[i];
    }
}
