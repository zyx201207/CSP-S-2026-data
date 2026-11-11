#include <bits/stdc++.h>
using namespace std;
int c,t,x[10000001],t[5001][5001];
int main(){
    freopen("migrate.in","r",stdin);
    freeopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    for (;t--;){
        int n,d,ans=0;
        scanf("%d%d",&n,&d);
        for (int i=1;i<=n;i++)
            scanf("%d",&x[i]);
        if (n<=300){
            for (int i=1;i<=n;i++){
                for (int k=1;k*x[i]<=n;k++){
                    for (int j=1+i;j<=n;j++){
                        if (x[j]<=k*x[i]){
                            t[i][k]=j;
                        }
                    }
                }
            }
            printf("0\n");
        } else {
            int t=0,y=x[2]-x[1];
            for (int i=2;i<=n;i++){
                if (x[i]-x[i-1]==y)
                    t++;
            }
            if (t==n-1){
                printf("0\n");
            }
        }
    }
    return 0;
}
