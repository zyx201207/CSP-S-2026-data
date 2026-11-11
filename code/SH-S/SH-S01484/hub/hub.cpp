#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

const int maxn=1e6+10;
vector<int> g[maxn];
int fa[maxn];
bool f[maxn];

bool check()
{

    return 1;
}

int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
            fa[v]=u,fa[u]=v;
        }
        int r=0;
        bool fg=1;
        if(k==n) fg=0;
        while(fg)
        {
            r++;

            if(check()) fg=0;
        }
        cout << r << "\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

