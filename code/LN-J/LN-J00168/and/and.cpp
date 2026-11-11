#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
int a[20005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {

        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=n;i>n-m;i--)
    {
        if(i==n)
        {
            ans=a[i];
            continue;
        }
        ans=ans&a[i];

    }

    cout<<ans;
    return 0;
}
