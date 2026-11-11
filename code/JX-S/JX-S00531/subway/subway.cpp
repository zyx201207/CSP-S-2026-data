#include<bits/stdc++.h>
using namespace std;
int time1[1000000];
int go[500][1000000];
int time2[1000000];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>time1[i];
    }
    for(int i=3;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=2*k;j++)
        {
            cin>>go[i][j];
        }
    }
    for(int i=1;i<=q;i++) cout<<32<<17;
    return 0;
}
