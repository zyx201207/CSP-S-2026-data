#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n,t;
    cin>>m>>n;
    if(m==1)
    {
        int maxa=0;
        for(int i=1;i<=n;i++)
        {
            cin>>t;
            maxa=max(maxa,t);
        }
        cout<<maxa;
    }
    else if(m==n)
    {
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            cin>>t;
            sum=sum&&t;
        }
        cout<<sum;
    }

    return 0;
}
