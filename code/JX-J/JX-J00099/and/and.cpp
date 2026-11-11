#include<bits/stdc++.h>
using namespace std;
int m,n,max1;
long long a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(max1<a[i])max1=a[i];
        }
        cout<<max1;
        return 0;
    }
    if(m==n)
    {
        max1=a[1];
        for(int i=2;i<=n;i++)max1=a[i]&max1;
        cout<<max1;
        return 0;
    }
    return 0;
}
