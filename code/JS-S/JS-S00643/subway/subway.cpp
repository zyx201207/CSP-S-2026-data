#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[505];
int sub[505][505];
struct sb
{
    int from,now,w,sss;
};
sb b[250005];
bool f[505];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int id;
            cin>>id;
            cin>>sub[i][id];
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<(w[x]+w[y])*2<<endl;
    }
    return 0;
}
/*
        O    D
      ----- /
        |
       / \





*/
