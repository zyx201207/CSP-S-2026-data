#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n,m,a[200005];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    if(m==1)
    {
        sort(a+1,a+n+1);
        cout<<a[n];
    }
    if(m==2)
    {
        int mx;
        mx=a[1]&a[2];
        for(int i=1;i<=n-1;i++)
            for(int j=i+1;j<=n;j++)
            {
                if((a[i]&a[j])>mx)
                    mx=a[i]&a[j];
            }
            cout<<mx;
    }
    if(m==n)
    {
        int z=a[1];
        for(int i=2;i<=n;i++)
        {
        z&=a[i];
        }
        cout<<z;
    }
    return 0;
}
