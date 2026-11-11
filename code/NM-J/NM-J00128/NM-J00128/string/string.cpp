#include <bits/stdc++.h>
using namespace std;

using LL=long long;

LL m,num,cnt,n;
char d;
stack <char> a;
stack <char> c;
stack <char> b;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&m);
    for(LL i=1;i<=m;i++)
    {
        scanf("%lld %c",&n,&d);
        num+=n;
        for(LL i=1;i<=n;i++)
        {
            a.push(d);
            b.push(d);
        }
    }
    for(LL i=1;i<=num;i++)
    {
        c.push(a.top());
        a.pop();
    }
    LL mun=num/2+num%2;
    for(LL i=1;i<=mun;i++)
    {
        if(c.top()!=b.top()) cnt++;
        c.pop();
        b.pop();
    }
    printf("%lld",cnt);
    return 0;
}
