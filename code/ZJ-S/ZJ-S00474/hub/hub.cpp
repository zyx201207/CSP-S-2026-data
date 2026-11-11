#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
    char c=getchar();
    while (!isdigit(c))
        c=getchar();
    long long ans=0;
    while (isdigit(c))
    {
        ans=ans*10+c-48;
        c=getchar();
    }
    return ans;
}
void write(const long long x)
{
    if (x>9)
        write(x/10);
    putchar(x%10+48);
    return;
}
struct edge
{
    int to,next;
}a[2000001];
int cnt,head[1000001];
inline void addedge(const int u,const int v)
{
    a[++cnt].next=head[u];
    head[u]=cnt;
    a[cnt].to=v;
    return;
}
namespace test_1
{
    struct DSU
    {
        vector<int>pre,siz;
        DSU(const int n):pre(n+1),siz(n+1,1){iota(pre.begin(),pre.end(),0);}
        int find(int x)
        {
            int r=x;
            while (x!=pre[x])
                x=pre[x];
            while (r!=x)
            {
                const int j=pre[r];
                pre[r]=x;
                r=j;
            }
            return x;
        }
        void merge(int x,int y)
        {
            x=find(x);y=find(y);
            if (x==y)
                return;
            if (siz[x]<siz[y])
                swap(x,y);
            pre[y]=x;
            siz[x]+=siz[y];
            return;
        }
    };
    int s[1000000];
    void dfs(const int t,const int n,const int k)
    {
        if (t==k)
        {
            
        }
        for (int i=t==0?1:s[t-1]+1;i<=n;++i)
        {
            s[t]=i;
            dfs(t+1,n,k);
        }
    }
    int main(const int n,const int k)
    {

        return 0;
    }
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    const int c=read();
    int T=read();
    while (T--)
    {
        cnt=0;
        const int n=read(),k=read();
        fill(head+1,head+n+1,0);
        for (int i=1;i<n;++i)
        {
            const int u=read(),v=read();
            addedge(u,v);
            addedge(v,u);
        }
        test_1::main(n,k);
        puts("0");
    }
    return 0;
}