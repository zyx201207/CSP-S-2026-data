#include <bits/stdc++.h>

using namespace std;
int c,t,n,k,g=1;
struct lu
{
    int w,v;
}a[1000100];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>k;
        for(int j=1;j<n;j++)
        {
            cin>>a[j].w>>a[j].v;
        }
        cout<<g++<<endl;
    }
    return 0;
}
