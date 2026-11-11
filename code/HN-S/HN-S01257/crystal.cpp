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
const int N=5e5+5;
int a[N],s[N],n,id[N];
priority_queue<int>q;
inline bool cmp(int x,int y)
{
    return (x-1)*(a[x])-s[x-1]+s[n]-s[x]-(n-x+1)*a[x]<(y-1)*(a[y])-s[y-1]+s[n]-s[y]-(n-y+1)*a[y];
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=_;rint m=_;
    for(rint i=1;i<=n;++i) a[i]=_,id[i]=i;
    sort(a+1,a+n+1);
    for(rint i=1;i<=n;++i) s[i]=s[i-1]+a[i];
    sort(id+1,id+n+1,cmp);
    // cerr<<mn<<' '<<id<<endl;
    rint ans=0;
    rint s=0,as=0;
    for(rint d=1;d<=min(50ll,n);++d)
    {
        rint i=id[d];
        s=as=0;
        for(rint j=1;j<=n;++j)
        {
            rint w=abs(a[i]-a[j]);
            if(w+s<=m) s+=w,q.push(w),++as;
            else
            {
                if(!q.empty()&&w<q.top()) s-=q.top(),q.pop(),--as;
                if(s+w<=m) {q.push(w);++as;s+=w;}
            }
            ans=max(ans,as);
        }
        while(!q.empty()) q.pop();
        ans=max(ans,as);
    }
    out(ans),pc('\n');
    return 0;
}//穗穗平安～