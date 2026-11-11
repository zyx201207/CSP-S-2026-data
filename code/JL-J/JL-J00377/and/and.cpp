#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,c=-1,d;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            d=a[i]&a[j];
            if(c<d)
            {
                c=d;
            }
        }

    }
    cout<<c;
    return 0;
}
