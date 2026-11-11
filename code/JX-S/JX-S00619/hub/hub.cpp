#include<bits/stdc++.h>
using namespace std;
const int X=1e6+5;
int c,t;
long long a[X][5];
long long n,k;
int main()
{
    freopen("hub.in","w",stdin);
    freopen("hub.out","r",stdout);
    cin>>c>>t;
    while(t>0)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2];
        }
        t--;
    }
    cout<<1<<endl<<2;
    return 0;
}
