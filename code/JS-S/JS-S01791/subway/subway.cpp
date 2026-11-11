#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef pair<int,int> PII;
int n,m,a[N],c,d,q,g[505][N],dis[N],w[N];
bool vis[N];
long long read(){
    char ch=getchar();long long a=0;
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){a=a*10+ch-'0';ch=getchar();}
    return a;
}
void print(long long a)
{
    if(a<0){putchar('-');a=-a;}
    if(a>10)print(a/10);
    putchar(a%10+'0');
}
void dij(int st)
{
    for(int i=1;i<=m;i++)
        dis[i]=0x3f3f3f3f,vis[i]=0;
    priority_queue<PII,vector<PII>,greater<PII>>q;
    q.push({0,st});
    dis[st]=0;
    while(!q.empty())
    {
        int wi=q.top().first,from=q.top().second;
        q.pop();
        if(vis[from])
            continue;
        vis[from]=1;
        for(int i=1;i<=n;i++)
        {
            if(g[i][from]!=0)
            {
                for(int to=1;to<=m;to++)
                {
                    if(to==from||g[i][to]==0)
                        continue;
                    int distan=g[i][from]+g[i][to];
                    if(wi+distan<dis[to])
                    {
                        dis[to]=wi+distan;
                        q.push({dis[to],to});
                    }
                }
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++)
    {
        w[i]=read();
    }
    for(int i=1;i<=n;i++)
    {
        int num=read();
        for(int j=1;j<=num;j++)
        {
            int to=read(),k=read();
            g[i][to]=k;
        }
    }
    while(q--)
    {
        int s=read(),e=read();
        dij(s);
        print(w[s]+w[e]+dis[e]);
        putchar('\n');
    }
    return 0;
}
