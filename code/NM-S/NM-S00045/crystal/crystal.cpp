#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m;
long long shu[N];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>shu[i];
    }
    sort(shu,shu+n+1);
    if(n==1)
    {
        cout<<1;
        return 0;
    }else
    {
        if(n==2)
        {
            int kskbl=shu[2]-shu[1];
            cout<<(m<kskbl?1:2);
        }
    }
    return 0;
}
