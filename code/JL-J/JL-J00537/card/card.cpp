#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500010];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cout<<n<<" "<<m<<" "<<a[1];
    return 0;
}
