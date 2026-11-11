#include<bits/stdc++.h>

using namespace std;

const int N=5e5+10;
const int M=3e5+10;
int n,m;
int a[N];
int last[M];
int ans[M];
int tmp[N];
bool taskA=1;

void solveTaskA()
{
    for(int i=1;i<=m;i++)
    {
        printf("%d ",last[i]);
    }
}

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=2;i<=n;i++)
        if(a[i]<a[i-1])
            taskA=0;
    for(int i=n;i>=1;i--)
    {
        if(last[a[i]]==0)
            last[a[i]]=i;
    }
    if(taskA)
    {
        solveTaskA();
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        int now=i,j=1;
        while(now<=n)
        {
            ans[a[now]]++;
            now=last[a[now]]+1;
        }
    }
    for(int i=1;i<=m;i++)
    {
        printf("%d ",ans[i]);
    }
    return 0;
}
