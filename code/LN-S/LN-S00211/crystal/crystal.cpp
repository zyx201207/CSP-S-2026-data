#include<bits/stdc++.h>
using namespace std;
int a[10000005],b[1000005];
int c;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<0)
        {
            a[i]=a[i]*-1;
        }
    }
    sort(a,a+n+1);

    c=a[2]-a[1];
    //cout<<c[1]<<"111111";
    int k=0,tot=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]+c==a[i+1] || a[i]==a[i+1])
        {
            k++;
            //cout<<i<<" "<<"这是k"<<k<<" ";
        }
    }
    //cout<<k;
    if(k==n || k==n-1)
    {
        tot=m/c;
        //cout<<" "<<tot<<" ";
        for(int j=1;j<=n;j++)
        {
            b[j]=b[j-1]+j-1;
            //cout<<b[j]<<" ";

        }
        for(int j=1;j<=n;j++)
        {
            if(tot>=b[j] && tot<b[j+1])
            {
                cout<<j;
                return 0;
            }
            else if(tot==b[j+1])
            {
                cout<<j+1;
            return 0;
            }
        }

    }
    else
    {
        cout<<n-1;
        return 0;
    }
    return 0;
}
