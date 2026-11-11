#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a,b,x[100005],y[10005],maxx=0;
    cin>>a>>b;
    for(int i=1;i<=a;i++)
    {
        cin>>x[i];
    }
    for(int i=1;i<=b;i++)
    {
        for(int j=1;j<=a;j++)
        {
            maxx=max(maxx,x[j]);
        }
        y[a]=maxx;
    }
    cout<<y[1]&y[2]&y[3];
    return 0;
}
