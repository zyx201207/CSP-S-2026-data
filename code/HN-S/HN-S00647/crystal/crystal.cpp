#include <bits/stdc++.h>

using namespace std;

long long n,m,x,s,zzz;
long long a[20000000];
long long b[20000000];
long long c[20000000];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        b[a[i]]++;
    }
    sort(a+1,a+1+n);
    for(long long i=1;i<=n;i++)
    {
        if(i+1<=n)
            c[i]=a[i]-a[i+1];
    }
    sort(c+1,c+1+n);

    for(long long i=1;i<=n;i++)
    {

        if(x+x+c[i]<m*-1)
        {
            s=a[i];
            zzz=i+b[i];
            cout<<i+b[i]<<endl;
            return 0;
        }
        x+=x+c[i];
        //cout<<'='<<x<<endl;
    }
    cout<<zzz;
    return 0;
}


