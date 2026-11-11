#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int va;
    bool vis=1;
};
Node a[40][200005];
long long ans;
void bin(int x,int i)
{
    int id=0;
    while(x)
    {
        a[++id][i].va=x%2;
        x/=2;
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        bin(x,i);
    }
    bool f=0;
    for(int i=35;i>=1;i--)
    {
        bool f=0;
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            if(a[i][j].va==1&&a[i][j].vis)
            {
                f=1;
                cnt++;
            }
        }
        if(f)
        {
            bool flag=1;
            for(int j=1;j<=n;j++)
            {
                if(!a[i][j].va&&cnt>=m)
                {
                    for(int k=1;k<=35;k++)
                        a[k][j].vis=0;
                }
                if(cnt<m)
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                ans+=pow(2,i-1);
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
