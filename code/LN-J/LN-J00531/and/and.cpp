#include<bits/stdc++.h>
using namespace std;
long long a[100005],maxx;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxx=max(a[i],maxx);
    }
    if(m=1)cout<<maxx;
    return 0;
}
