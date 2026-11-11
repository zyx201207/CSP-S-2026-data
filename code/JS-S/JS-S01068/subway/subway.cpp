#include <bits/stdc++.h>

using namespace std;

const int N=500005;

struct node{
    int x,y;
};

int n,m;
int d,q;

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int abcdefg;
    cin>>abcdefg;
    cin>>n>>m;
    cin>>d>>q;
    vector<int> w(m+1,0);
    for (int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    str[m+1][N];
    sti[m+1][N];
    for (int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for (int j=1;j<=k;j++)
        {
            int b,c;
            cin>>b>>c;

        }
    }
    for (int i=1;i<=n;i++)
    {
        int xr,yr;
        cin>>xr>>yr;
    }
    for (int i=1;i<=m;i++)
    {
        for (auto j:str[i])
        {
            cout<<str[i][j-2]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
