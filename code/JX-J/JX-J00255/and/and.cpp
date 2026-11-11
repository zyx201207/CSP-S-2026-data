#include<bits/stdc++.h>
const int N=1e6;
long long a[N];
using namespace std;
int main ()
{


    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,u=0,p=0;
    cin>>n>>m;

    for(int i = 1;i<=n;i++)
    {

        cin>>a[i];
    }
    for(int i =1;i<=n;i++)
    {

        p =a[i]&a[i+1];
        u = max(u,p);
    }
    cout<<u;
    return 0;
}
