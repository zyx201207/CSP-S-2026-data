#include<bits/stdc++.h>
using namespace std;
int n,m,a[676767],b=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(m>=a[i+1]-a[i])
        {
            m=m-a[i+1]+a[i];
            a[i]=a[i+1];
            if(a[i]==a[i+1])
            {
                b++;
            }
        }
        else
        {
            break;
        }
    }
    cout<<b;
}
