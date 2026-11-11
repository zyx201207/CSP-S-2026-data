#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,k;
vector<int> t[1000001];
bool flaga=true;
void do_A()
{
    int m=n/2;
    if(k>=m+1) cout<<1;
    if(k==1) cout<<m;
    if(k==2) cout<<m-1;
    else cout<<(m-k)/2+2;
}
void solve()
{
    cin>>n>>k;
    flaga=n&1;
    int m=n/2;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        if(((u<=m&&u!=i||m+1<=u&&u<=n-1&&u!=i-m)||v!=i+1)) flaga=false;
    }
    if(flaga) do_A();
    return ;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    for(int i=1;i<T;i++)
    {
        solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
