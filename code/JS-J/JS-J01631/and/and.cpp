#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<1<<endl;
    sort(a,a+n);
    for(int i=n-m;i<n;i++)
    {
        if(i==n-m)
        {
            ans=a[i];
            continue;
        }
        ans&=a[i];
    }
    cout<<ans<<endl;
    return 0;
}
