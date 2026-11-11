#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,p,w[2000005],t[2000005],sum;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
        sum+=w[i];
    }
    cout<<w<<endl<<w-9;
    return 0;
}
