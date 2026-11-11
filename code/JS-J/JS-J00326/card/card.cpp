#include<bits/stdc++.h>
using namespace std;
int n,m,a[5000005],sum[3000005];
int main()
{
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        int tail=1;
        for(int j=i;j<=n;j++)
        {
            for(int m=1;m<=tail-1;m++)
            {
                if(a[m]==a[tail])
                {
                    tail=m;
                    break;
                }
                else
                {
                    tail++;
                    a[tail]=a[j];
                }
            }
        }
        //cout<<tail<<endl;
        for(int l=1;l<=tail;l++)
        {
            sum[a[l]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<sum[i]<<' ';
    }
    return 0;
}
