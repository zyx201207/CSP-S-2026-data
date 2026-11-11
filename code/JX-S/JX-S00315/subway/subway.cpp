#include <bits/stdc++.h>
using namespace std;
int taketime[1005];
int linesum[505];
bool linepass[505][1005];
int walktime[505][1005];
int graph[25125][25125];
int temp;
int x,y;
int c,n,m,d,q;
void ask(int x,int y)
{

}
int main()
{
    memset(linepass,0,sizeof(linepass));
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++)
    {
        scanf("%d",&taketime[i]);
    }
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&linesum[i]);
        for (int j=1;j<=linesum[i];j++)
        {
            cin>>temp;
            linepass[tmp]=1;
            scanf("%d",&walktime[i][temp]);
        }
    }

    for (int i=1;i<=q;i++)
    {
        cin>>x>>y;
        ask(x,y);
    }
}
