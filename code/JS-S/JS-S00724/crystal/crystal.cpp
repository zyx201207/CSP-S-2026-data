#include<bits/stdc++.h>
using namespace std;

int n;
long long m;


int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[j]>a[j+1])
            {
                int n=a[j];
                a[j]=a[j+1];
                a[j+1]=n;
            }
        }
    }
    int y=n;
    n=1;
    for(int i=1;;i++)
    {
        if(a[n]==a[n+1])
            n++;
        a[n]++;
        m-=n;
        if(m<=0)
        {
            break;
        }
    }
    for(int i=n+1;;i++)
    {
        if(a[i]==a[n])
        {
            n++;
        }
        else
        {

            break;
        }
    }
    cout<<n;
    return 0;
}
