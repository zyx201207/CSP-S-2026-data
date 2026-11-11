#include<bits/stdc++.h>
using namespace std;
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
struct FSI{
    template<typename T>
    FSI& operator >> (T &res){
        res=0;T f=1;char ch=getchar();
        while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
        while (isdigit(ch)){res=res*10+ch-'0';ch=getchar();}
        res*=f;
        return *this;
    }
}scan;
typedef long long ll;
const int N=2e6+10;
int c,T,n,i,f[N],g[N];
ll d,a[N],ans,x;
void fun()
{
    int i,j,k,l,pos;
    for (i=1;i<=n-1;i++)
    {
        f[i]=0;g[i]=1;
        for (j=i+1,l=i;j<=n;j++)
        {
            while (l<j&&a[j]-a[l]>d) l++;
            if (l==j) break;
            f[j]=f[l]+1;g[j]=0;
            for (k=l;k<j;k++)
            {
                if (f[k]+1==f[j]) g[j]+=g[k];
                else break;
                if (g[j]>2){g[j]=3;break;}
            }
            if (g[j]==2) ans++;
        }
    }
}
void work()
{
    scan>>n>>d;
    for (i=1;i<=n;i++) scan>>a[i];
    if (c>=1&&c<=10)
    {
        ans=0;
        fun();
        printf("%lld\n",ans);
        return;
    }
    if (n==1){puts("0");return;}
    if (a[2]-a[1]>d){puts("0");return;}
    x=d/(a[2]-a[1]);
    ans=0;
    for (i=1;i<=n;i++)
    {
        if (i%x!=0&&i%x==x-1&&i/x==1) ans+=n-i;
    }
    printf("%lld\n",ans);
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scan>>c>>T;
    while (T--) work();
    return 0;
}