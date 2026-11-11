#include<bits/stdc++.h>
using namespace std;
int n,a[500005],m,ton[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ton[a[i]]++;
    }
    /*if(n==4&&m==3) cout<<"3 1 4";
    else if(n==10&&m==3) cout<<"10 3 3";
    else cout<<"1 1 1";*/
    for(int i=1;i<=n;i++)
    {
        ton[i]*=n;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int pai=a[j];
            for(int k=j-1;k>=i;k--)
            {
                if(a[k]==pai)
                {
                    for(int l=k;l<=j;l++)
                    {
                        ton[a[l]]--;
                    }
                }
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ton[i]<<endl;
    }
    return 0;
}