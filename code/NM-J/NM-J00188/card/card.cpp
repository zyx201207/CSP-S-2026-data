#include<bits/stdc++.h>
using namespace std;
int a[1000000],b[1000000],s[1000000];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,k=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            for(int l=1;l<k;l++)
            {
                if(b[l]==a[j])
                {
                    k=l;
                    break;
                }
            }
            b[k]=a[j];
            k++;
        }
        for(int j=1;j<k;j++)
        {
            s[b[j]]++;
        }
        k=1;
    }
    for(int i=1;i<=m;i++)
    {
        cout<<s[i]<<" ";
    }
}
