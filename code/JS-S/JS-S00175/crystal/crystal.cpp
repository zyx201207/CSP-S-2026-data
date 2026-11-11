#include<bits/stdc++.h>
using namespace std;
#define inf 0x37373737
const int N=5e5+5;
int n,an=1;long long m;
long long a[N];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    long long d=a[2]-a[1];
    for(long long j=1;j<=n/2;j++)
    {
        m-=j*d;
        if(m>=0)
        {
            an++;
            if(m>=j*d)
            {
                m-=j;
                an++;
            }
        }
        else
            break;
    }
    cout<<an<<'\n';
    return 0;
}