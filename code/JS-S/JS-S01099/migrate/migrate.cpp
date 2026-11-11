#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
            f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
        x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*f;
}
void cmax(int &x,int y)
{
    x=max(x,y);
}
void cmin(int &x,int y)
{
    x=min(x,y);
}
void write(int x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        write(x/10);
    putchar('0'+x%10);
}
const int N=2e6+5;
bool ttt;
int n,m,a[N],fl[N],fr[N],cl[N],cr[N],ans,bg[N],ed[N],sr[N];
bool sss;
void solve(int L,int R)
{
  //  cout<<"D"<<L<<' '<<R<<endl;
    for(int i=L,j=L;i<=R;i++)
    {
        if(j<i)
            j=i;
        while(j<R&&a[j+1]-a[i]<=m)
            j++;
        fr[i]=j;cl[j]++;
      //  cout<<"R"<<i<<' '<<fr[i]<<endl;
    }
    for(int i=R,j=R;i>=L;i--)
    {
        if(j>i)
            j=i;
        while(j>L&&a[i]-a[j-1]<=m)
            j--;
        fl[i]=j;cr[j]++;
        bg[j]=i;cmax(ed[j],i);
     //   cout<<"L"<<i<<' '<<fl[i]<<endl;
    }
    for(int i=R;i>=L;i--)
    {
        if(fl[fr[i]]==i)
        {
            cr[i]+=cr[fr[i]];
        }
    //    cout<<"CR"<<i<<' '<<cr[i]<<endl;
    }
    //cl cr doesn't count itself;
    for(int i=L;i<=R;i++)
    {
        if(fr[fl[i]]==i)
        {
            cl[i]+=cl[fl[i]];
        }
        sr[i]=sr[i-1]+cr[i]+1;
    }
    for(int i=L,x,tox,lm,rm,cur;i<=R;i++)
    {
        x=fr[i];
        if(i+1==x)
            continue;
        lm=bg[x-1];rm=fr[x-1];
    //    cout<<i<<' '<<x<<' '<<lm<<' '<<rm<<endl;
        if(lm>rm)
            break;
        cmax(lm,x+1);cmin(rm,fr[x]);
        if(lm>rm)
            break;
        cur=1;
        if(fl[x-1]==i)
            cur+=cl[i];
        if(rm==fr[x])
            ans+=cur*(cr[rm]+1);
        else
            ans+=cur;
        if(lm<rm)
            ans+=(rm-lm)*cur;
    }
  //  exit(0);
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int sub=read(),tc=read();
    while(tc--)
    {
        n=read(),m=read();
        for(int i=1;i<=n;i++)
        {
            a[i]=read();cl[i]=0;cr[i]=0;
            fl[i]=0,fr[i]=0;bg[i]=n+1,ed[i]=0;sr[i]=0;
        }
        int la=1;ans=0;
        for(int i=1;i<n;i++)
        {
            if(a[i+1]-a[i]>m)
            {
                if(la<i)
                    solve(la,i);
                la=i+1;
            }
        }
        if(la<n)
            solve(la,n);
     //   cout<<"D"<<n<<' '<<m<<' '<<a[n]-a[1]<<' '<<a[1]<<' '<<a[n]<<endl;
        write(ans);puts("");
    }
    return 0;
}
