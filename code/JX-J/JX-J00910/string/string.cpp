#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N];
char b[N];
int n,l,r,ans;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    l=1,r=n;
    while(l<r)
    {
        if(a[l]<a[r])
        {
            if(b[l]!=b[r]) ans+=a[l];
            a[r]-=a[l++];
        }
        else if(a[l]==a[r])
        {
            if(b[l]!=b[r]) ans+=a[l];
            l++,r--;
        }
        else
        {
            if(b[l]!=b[r]) ans+=a[r];
            a[l]-=a[r--];
        }
    }
    cout<<ans;
    return 0;
}
