#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
struct node
{
    long long x;
    string s;
}a[N];
long long ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    m=n;
    for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].s;
    for(int i=1;i<=n;i++)
    {
        if(m<=i) break;
        long long x=a[i].x;
        while(x)
        {
            if(x==0) break;
            if(x<a[m].x)
            {
                a[m].x-=x;
                if(a[m].s!=a[i].s) ans+=x;
                break;
            }
            x-=a[m].x;
            if(a[m].s!=a[i].s) ans+=a[m].x;
            m--;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

