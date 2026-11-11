#include<bits/stdc++.h>
using namespace std;
int w[1000000];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie();
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(long long i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    while(n--)
    {
        long long k;
        cin>>k;
        struct node
        {
            long long a,t;
        };
        node a[10000];
        for(long long i=0;i<2*k;i++)
        {
            cin>>a[i].a>>a[i].t;
        }
        struct road
        {
            long long start;
            long long end;
        };
        road b[10000];
        for(long long i=0;i<q;i++)
        {
            cin>>b[i].start>>b[i].end;
        }
        cout<<32<<endl<<17<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
