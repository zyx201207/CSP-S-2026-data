#include <bits/stdc++.h>
#define uns unsigned
using namespace std;

uns int c,n,m,d,q;

inline uns int qr()
{
    uns int a=0;
    char c=getchar();
    while(c<'0' || c>'9')
        c=getchar();
    while(c>='0' && c<='9')
    {
        a=a*10+c-'0';
        c=getchar();
    }
    return a;
}

int main()
{
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    return 0;
}
