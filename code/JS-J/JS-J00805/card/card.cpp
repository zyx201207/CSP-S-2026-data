#include<iostream>
#include<vector>
using namespace std;
bool q;
long long read()
{
    q=0;
    int c,d=0;
    long long x=0;
    c=getchar();
    while(c<'0'||c>'9')
    {
        c=getchar();
        if(c==-1)
        {
            q=1;
            return 0;
        }
        d=c;

    }
    while(c>='0'&&c<='9'||c==-1)
    {
        x=x*10+c-'0';
        c=getchar();
    }
    if(d=='-')
    {
        x*=-1;
    }
    return x;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    n=read();
    m=read();
    vector<long long> a(n+1),cnt(m+1,0),sizeb(m+1,0),b(m+1,-1);
    for(long long i=0;i<n;i++)
    {
        a[i]=read();
        b[a[i]]=i;
        sizeb[a[i]]++;
    }
    long long j;
    for(long long i=0;i<n;i++)
    {
        j=i;
        while(j<=n-1)
        {
            cnt[a[j]]++;
            if(sizeb[a[j]]>1)
            {
                j=b[a[j]]+1;
            }
            else
            {
                j++;
            }
        }
        sizeb[a[i]]--;
    }
    for(long long i=1;i<=m;i++)
    {
        cout<<cnt[i]<<' ';
    }
    return 0;
}
