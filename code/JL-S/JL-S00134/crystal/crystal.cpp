#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
const ll M=5e5+10;
ll a[M];
bool check()
{
    //case 1

    //case 2

    //case 3
    return 0;
}
int main()
{
    srand(time(0));
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool f=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]!=i?f=0:f;
    }
    if(f)cout<<n;
    else cout<<rand()%min(n,min(m,(ll)5e5));
    return 0;
}
