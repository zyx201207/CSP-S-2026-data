#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010];
int f[5010][5010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    bool ok=true;
    for(int i=1;i<=n;i++)
        if(a[i]<a[i-1])
            ok=false;
    if(ok){
        for(int i=1;i<=m;i++){
            int l=0,r=n+1;
            while(l+1<r){
                int M=(l+r)/2;
                if(a[M]<=i)
                    l=M;
                else
                    r=M;
            }
            printf("%d",l);
            if(i!=m)
                printf(" ");
        }
        printf("\n");
        return 0;
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=n;j++)
            f[i][j]=f[i+1][j];
        f[i][a[i]]++;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;){
            if(f[j+1][a[j]]==0)
                ans[a[j]]++,j++;
            else{
                int l=j,r=n+1;
                while(l+1<r){
                    int M=(l+r)/2;
                    if(f[M][a[j]]!=0)
                        l=M;
                    else
                        r=M;
                }
                ans[a[j]]++;
                j=l+1;
            }
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d",ans[i]);
        if(i!=m)
            printf(" ");
    }
    printf("\n");
    return 0;
}
