#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long z[500050];
long long T,ans,N;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int q=1;q<=n;q++)
    {
        cin>>z[q];
    }
    sort(z+1,z+n+1);
    N=1;
    long long x=n;
    for(int q=n;q>=1;q--)
    {
        if(T+z[x]-z[q]<=m)
        {
            N++;
            T=T+z[x]-z[q];
        }
        else
        {
            while(T+z[x]-z[q]>m)
            {
                T-=(N-1)*(z[x]-z[x-1]);
                x--;
                N--;
                if(N==1)
                {
                    x=q;
                    T=0;
                    break;
                }
            }
            N++;
            T=T+z[x]-z[q];
        }
        ans=max(ans,N);
    }
    cout<<ans-1;
}
