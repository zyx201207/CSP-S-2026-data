#include<bits/stdc++.h>
using namespace std;
long long n,m;
constexpr int N=2e5+10;
long long ans;
struct ll
{
    int sum;
    int id;
    long long en;
}b[N];
char c;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long cnt;
    cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>m>>c;
        b[i].sum=m;
        b[i].id=c-'a';
        b[i].en=cnt+m;
        cnt+=m;
    }
    long long l=1,r=n;
    for(long long i=1;i<=cnt/2;i++)
    {
        long long j=cnt-i+1;
        if(i>b[l].en)
        {
            l++;
        }
        if(j<=b[r-1].en)
        {
            r--;
        }
        if(b[l].id!=b[r].id)
        {
            long long p=min(b[l].en-i,j-b[r-1].en-1);
            i+=p;
            ans+=(p+1);
        }
        else
        {
            long long p=min(b[l].en-i,j-b[r-1].en-1);
            i+=p;
        }
        if(l>=r)
        {
            break;
        }
    }
    cout<<ans;
    return 0;
}
