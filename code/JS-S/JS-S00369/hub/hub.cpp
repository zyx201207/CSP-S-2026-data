#include<bits/stdc++.h>
using namespace std;
int n,k;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            int u,v;
            cin>>u>>v;
        }
        if(k==n)
            cout<<0<<"\n";
        else if(k>=(n+1)/2)
            cout<<1<<"\n";
        else
        {
            int ans=0;
            if(k%2==1)
            {
                int m=(n+1)/2;
                ans=(m-k)/2;
            }
            else
            {
                int m=(n+1)/2;
                ans=(m+1-k)/2;
            }
            cout<<ans/2+1<<"\n";
        }
    }
    return 0;
}
