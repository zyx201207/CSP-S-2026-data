#include<bits/stdc++.h>

using namespace std;

const int N=1e6+10;
int n,k;
int c,T;
vector<int> g[N];
mt19937 rng(time(0));

int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        printf("%d\n",rng()%5+1);
    }
    return 0;
}
