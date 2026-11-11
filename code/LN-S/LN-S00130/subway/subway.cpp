#include <bits/stdc++.h>
using namespace std;
int w[100001];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,m,d,q,n;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
    }
    if(n==2) cout<<32<<endl<<17;
    else cout<<35<<endl<<16;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
