#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
struct node
{
    long long a;
    char b;
} x[N];
long long n,m,ans;
string q,p;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1; i<=n; i++)
    {
        cin>>x[i].a>>x[i].b;
        m+=x[i].a;
        for(long long j=1; j<=x[i].a; j++)
        {
            q+=x[i].b;
        }
    }
    for(long long i=0;i<=m/2; i++)
    {
        long long l=m-i-1;
        if(q[l]!=q[i])
        {
            ans++;
        }
    }
     cout<<ans;
    return 0;
}
