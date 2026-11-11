#include<bits/stdc++.h>
using namespace std;
int a,b,c[100000],d[10000],e[100000],n[10000];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>a>>b;
    for(int i=1;i<=a;i++)
    {
        cin>>c[i];
    }
    for(int i=1;i<=a;i++)
    {
        for(int j=i;j<=a;j++)
        {
            e[j]=c[j];
            d[c[j]]=1;
            for(int l=1;l<j;l++)
            {
                if(e[l]==c[j])
                {
                    for(int h=i;h<j;h++)
                    {
                        e[h]=0;
                        d[c[h]]=0;
                    }
                    d[c[j]]=1;
                }
            }
        }
        for(int p=1;p<=b;p++)
        {
            if(d[p]==1)
            {
                n[p]++;
            }
        }
        for(int o=1;o<=b;o++)
        {
            d[o]=0;
        }
        for(int s=1;s<=a;s++)
        {
            e[s]=0;
        }
    }
    for(int i=1;i<=b;i++)
    {
        cout<<n[i]<<" ";
    }
    return 0;
}
