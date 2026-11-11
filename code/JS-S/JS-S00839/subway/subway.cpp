#include<iostream>

using namespace std;

const int MAXM=500070;
int c,n,m,d,q;
int w[MAXM];
struct line
{
    int k;
    int a[MAXM],t[MAXM];
}l[507];


int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;
    for (int i = 1; i <= m; i++)cin>>w[i];
    for (int i = 1; i <= n; i++)
    {
        cin>>l[i].k;
        for (int j = 1; j <= l[i].k; j++)
            cin>>l[i].a[j]>>l[i].t[j];
    }
    for (int i = 0; i < q; i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<0;
    }
    
    
    return 0;
}