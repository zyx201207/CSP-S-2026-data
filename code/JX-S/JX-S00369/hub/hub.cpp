#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int a[500005],b[500005];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=n-1;i++) cin>>a[i]>>b[i];
        cout<<((n&k)-1);
    }
    return 0;
}
