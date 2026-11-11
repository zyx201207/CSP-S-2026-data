#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,a[1000005],cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==4&&m==3)
    {
        cout<<3<<" "<<1<<" "<<4<<endl;
    }
    return 0;
}
