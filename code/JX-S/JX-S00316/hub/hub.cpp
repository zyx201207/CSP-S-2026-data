#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie();
    long long c,t;
    cin>>c>>t;
    int qwe=t;
    while(t--)
    {
        long long n,k;
        cin>>n>>k;
        long long u[10000],v[10000];
        for(int i=1;i<=n-1;i++)
        {
            cin>>u[i]>>v[i];
        }
        for(int i=1;i<=qwe;i++)
        {
            cout<<i<<endl;
        }
    }
    return 0;
}
