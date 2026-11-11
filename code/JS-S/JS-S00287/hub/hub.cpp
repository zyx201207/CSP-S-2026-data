#include<bits/stdc++.h>
using namespace std;
struct node
{
    int u,v;
    long long vic;
    bool operator < (const node& nx) const {
        return vic > nx.vic;
    }
};
long long read()
{
    long long x=0;
    short f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')  f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
void wit(long long x)
{
    if(x<=9)    putchar(x+'0');
    else{
        wit(x/10);
        putchar(x%10+'0');
    }
}
void write(long long x,bool enld)
{
    if(x>=0)    wit(x);
    else{
        putchar('-');
        wit(-x);
    }
    if(enld)    putchar('\n');
    else    putchar(' ');
}

const int N=5e5+13;
long long n,T,s,ss,k;
bool vis[N];
vector<int>e[N];
queue<int>Q;
long long dfs(int t)
{
    long long len=0,sz,ti;
    Q.push(t);
    for(int i=1;i<=n;i++)    vis[i]=0;
    vis[t]=1;
    sz=Q.size();
    while(sz!=0)
    {
        ti=0;
        for(int i=1;i<=sz;i++)
        {
            int nw=Q.front();
            Q.pop();
            s=nw;
            for(auto ed:e[nw])
            {
                ti++;
                if(vis[ed]==0)
                {
                    vis[ed]=1;
                    Q.push(ed);
                }
            }
        }
        len++;
        sz=Q.size();
    }
    return len/2;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    read();T=read();
    while(T--)
    {
        n=read();k=read();
        for(int i=1;i<n;i++)
        {
            int u,v;
            u=read();v=read();
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(1);
        write(dfs(s),1);
    }
    return 0;
}
