#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
int c,t,n,k,u[MAXN],v[MAXN],ans;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        memset(u,0,sizeof(u));
        memset(v,0,sizeof(v));
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            cin>>u[i]>>v[i];
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
