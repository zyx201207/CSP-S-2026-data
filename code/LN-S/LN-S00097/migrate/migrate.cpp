#include<bits/stdc++.h>
#define int long long
#define inf 1e18
using namespace std;
inline int read()
{
    int c=0,w=1;
    char ch=getchar();
    while(ch>'9'||ch<'0')
    {
        if(ch=='-')w=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        c=(c<<1)+(c<<3)+ch-48;
        ch=getchar();
    }
    return w*c;
}
#define maxn 2222222
int n,d;
int a[maxn];
int ans;
void dfs(int i,int l,int r,int k,int x)
{
    if(i>r||x>k)return;
    if(i==r)
    {
        if(k==x)ans++;
        return;
    }
    for(int t=1;t<=r-i+1;t++)dfs(i+t,l,r,k,x+1);
}
void Part1()
{
    int tot=0;
    for(int l=1;l<=n;l++)
        for(int r=l+1;r<=n;r++)
        {
            int maxx=0;
            for(int i=l+1;i<=r;i++)maxx=max(maxx,a[i]-a[i-1]);
            if(maxx>d)continue;
            //check whether arrive
            int cnt=0,res=0,lastl=l;
            for(int i=l;i<=r;i++)
            {
                if(a[i]-a[lastl]>d)cnt++,lastl=i-1;
            }
            if(a[r]-a[lastl]<=d)cnt++;
            //the shortest path
            ans=0;
            dfs(l,l,r,cnt,0);
            if(ans==2)tot++;
        }
    printf("%lld\n",tot);
}
void Part2()
{
    //cout<<a[2]-a[1]<<endl;
    int k=n+2;
    for(int i=1;i<=n;i++)
        if(a[i]-a[1]>d+d){k=i-1;break;}
    k--;
    if(k<=2)puts("0");
    else printf("%lld\n",n-k+1);
}
void solve()
{
    n=read(),d=read();
    for(int i=1;i<=n;i++)a[i]=read();
    if(n==1){puts("0");return;}
    bool vis=1;
    int st=a[2]-a[1];
    for(int i=2;i<=n;i++)
        if(a[i]-a[i-1]==st)continue;
       else{vis=0;break;}
    if(vis){Part2();return;}
    if(n<=195){Part1();return;}
    puts("A");
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c=read(),T=read();
    while(T--)solve();
    return 0;
}
