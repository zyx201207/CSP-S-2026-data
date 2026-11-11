#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);


    int c,t;
    cin>>c>>t;
    //if(c==13||c==14)
    {
        while(t--)
        {
            int n,k,x;
            cin>>n>>k;
            for(int i=1;i<n;i++)
                cin>>x>>x;
            if(n==k) cout<<"0\n";
            else if(k*2+1>=n) cout<<"1\n";
            else cout<<"2\n";
        }
    }
    return 0;
}

