#include<bits/stdc++.h>
using namespace std;
long long n,m,num;
long long t[500005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        long long a;
        cin>>a;
        t[a]++;
    }
    for(long long i=500005;i>0;i--)
    {
        if(t[i]==0)
        {
            continue;
        }
        if(t[i]>=m)
        {
            cout<<i;
            exit(0);
        }
        m-=t[i];
    }
    return 0;
}
