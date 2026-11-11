#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,a[N],ans,b[N];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=n/2;i++)
    {
        if(b[i]!=b[n+1-i])
        {
            ans+=a[n+1-i];
        }
    }
    cout<<ans;
    return 0;
}
