#include <bits/stdc++.h>
using namespace std;
int n,m,ans=-1000,t=9999999,a[1000005],f[1000005];
string s[10000005];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        while(a[i]>0)
        {
            f[i]+=a[i]%2;
            s[i]=a[i]%2;
            a[i]/=2;
        }

    }
    sort(f,f+n+1);
    if(m==1)
    {
        cout<<f[n];
    }
    if(m==2)
    {
        t=0;
        for(int i=1;i<=s[n].length();i++)
        {

            cout<<min(f[n],f[n-1]);
        }
    }
    else{
        for(int i=1;i<=m;i++)

        {
            t=min(t,f[n-i+1]);
        }
        cout<<t;
    }

    return 0;
}
