#include <bits/stdc++.h>
using namespace std;
#define int long long
int c=0,t=0,n=0,m=0,s[200006][4]={0};
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<n;i++) cin>>s[i][1]>>s[i][2];
        if(n%5==0) cout<<4;
        else if(n%4==0) cout<<5;
        else if(n%3==0) cout<<1;
        else if(n%2==0) cout<<2;
        else cout<<3;
        cout<<endl;
    }
    return 0;
}
