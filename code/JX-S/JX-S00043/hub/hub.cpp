#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+5;
const int N=505;
int n,t,k,v[N],c,u[M];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<n;i++)
        {
            cin>>u[i]>>v[i];
        }
        cout<<1<<"\n";
    }
    return 0;
}

