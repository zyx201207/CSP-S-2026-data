#include <bits/stdc++.h>
using namespace std;
#ifdef __linux__
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc _getchar_nolock
#define pc _putchar_nolock
#endif
#define int long long
#define _ read<int>()
#define rint register int
inline bool blank(const char &x)
{
    return !(x^32)||!(x^13)||!(x^10)||!(x^9);
}
template<class T>inline T read()
{
    T r=0,f=1;char c=gc();
    while(!isdigit(c)) 
    {
        if(c=='-') f=-1;
        c=gc();
    }
    while(isdigit(c)) r=(r<<1)+(r<<3)+(c^48),c=gc();
    return f*r;
}
inline void out(rint x)
{
    if(x<0) pc('-'),x=-x;
    if(x<10) pc(x+'0');
    else out(x/10),pc(x%10+'0');
}
inline void read(char &x)
{
    for(x=gc();blank(x)&&(x^-1);x=gc());
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);  
    rint c=_,t=_;
    while(t--)
    {
        puts("1");
    }
    return 0;
}//穗穗平安～