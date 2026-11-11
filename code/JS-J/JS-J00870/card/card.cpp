#include<bits/stdc++.h>
using namespace std;
const int N=3010;
int n,m,a[200010],cnt[N],last[N],f[N][N],ans[N];
pair<int,int> pos[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        cnt[a[i]]++;
        last[a[i]]=i;
    }
    for(int i=1;i<=m;i++) pos[i]={last[i],i};
    sort(pos+1,pos+m+1,greater<pair<int,int> >());
    f[a[n]][a[n]]=1;
    for(int i=1;i<=m;i++)
    {
        int x=pos[i].second;
        int p=last[x];
        int y=a[p+1];
        for(int j=1;j<=m;j++) f[x][j]=f[y][j];
        f[x][a[p]]=1;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            ans[j]+=f[i][j]*cnt[i];
        }
    }
    for(int i=1;i<=m;i++) printf("%d ",ans[i]);
    return 0;
}
