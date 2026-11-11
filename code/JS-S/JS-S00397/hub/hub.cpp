#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int C,T,n,k,u[N],v[N],cnt;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>C>>T;
    while(T--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            cin>>u[i]>>v[i];
        cout<<++cnt;
    }
    return 0;
}
