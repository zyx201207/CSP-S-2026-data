#include<cstdio>
#include<unordered_map>
using namespace std;
const int N=5e5+5;
int n,m,a[N],cnt[N],b[N],k;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        k=0;
        for(int j=i,p;j<=n;j++)
        {
            for(p=k;p>=1;p--){if(b[p]==a[j]) break;}
            if(p!=0) k=p;
            else b[++k]=a[j];
        }
        for(int j=1;j<=k;j++)
            cnt[b[j]]++;
    }
    for(int i=1;i<=m;i++) printf("%d ",cnt[i]);
    printf("\n");
}
