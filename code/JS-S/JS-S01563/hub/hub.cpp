#include<bits/stdc++.h>
using namespace std;
int a[100010];
int b[100010];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        cout<<n*13-k+5<<"\n";
    }
    return 0;
}
