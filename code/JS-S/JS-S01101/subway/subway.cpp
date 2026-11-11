#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
const int maxm=5e5+10;
int fa[maxm]
int dis[maxn][maxn][maxn];

int findd(int x)
{
    if(x==fa[x])
        return x;
    return fa[x]=findd(fa[x]);
}
int main()
{
    //freopen("subway.in","r",stdin);
    //freopen("shit4.out","w",stdout);
    return 0;
}
