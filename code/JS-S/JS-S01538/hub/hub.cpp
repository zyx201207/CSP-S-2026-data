#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    
    int ans=1;
    for(int i=1;i<=800000000;i++)ans=(ans*i+i);
    cout<<ans<<'\n';
    return 0;
}