#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
struct su
{
    long long a,t,w;
}s[500010];
su x[3030][3030];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>s[i].w;
    }
    for(int i=1;i<=n;i++)
    {
        int z;
        cin>>z;
        for(int j=1;j<=z;i++)
        {
            cin>>x[i][j].a>>x[i][j].t;
        }
    }
    while(q--)
    {
        int b,e,he=0;
        cin>>b>>e;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;i++)
            {
                if(x[i][j].a==b)he+=s[x[i][j].a].w+x[i][j].t;
            }
            for(int j=1;j<=n;i++)
            {
                if(x[i][j].a==e)he+=s[x[i][j].a].w+x[i][j].t;
            }
        }
        cout<<he<<endl;

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
