#include<bits/stdc++.h>
using namespace std;

int a[500000];
bool b[500000];
int page[300000];
int pa[300000];

freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

void cmp(int a[],int b[],int page[],i,n,m)
{
    for(int j=i;j<=n;j++)
    {
        int ans=0;
        page[a[i]]++;
    }
    for(int j=i;j<=n;j++)
    {
    }
    for(int j=1;j<=m;j++)
    {
        page[j]=0;
    }
}

int main()
{

    int n,m; scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int p; scanf("%d",&p);
        //page[p]++;
        a[i]=p;
    }
    void cmp(a,b,page,1,n,m);
    return 0;
}
