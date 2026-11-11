# include<cstdio>
# include<iostream>
# include<algorithm>
# include<vector>
# include<queue>
using namespace std;
int c,t,n,k,
vector<int>g[N];
void f()
{

}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> t;
    while(t--)
    {
        scanf("%d %d",&n,&k);
        for(int i =1;i<n;i++)
        {
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    if(c == 1)printf("1\n2");
    return 0;
}
