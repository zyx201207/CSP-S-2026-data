#include <bits/stdc++.h>
using namespace std;
int n,t,c,L[5000][5000];
int way[5000][5000];
long long d,x[5000];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    for(int i=0;i<t;i++){
        scanf("%d%lld",&n,&d);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                way[i][j]=0;
                L[i][j]=1<<29;
            }
        }
        for(int j=0;j<n;j++){
            scanf("%lld",&x[j]);
            for(int k=j;x[j]-x[k]<=d&&k>=0;k--){
                L[k][j]=1;
                L[j][k]=1;
                way[j][k]=1;
                way[k][j]=1;
            }
        }
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                for(int l=0;l<n;l++){
                    if(L[k][l]>=L[k][j]+L[j][l]){
                        L[k][l]=L[k][j]+L[j][l];
                        way[k][l]+=way[k][j]*way[j][l];
                    }
                }
            }
        }
        int ans=0;
        for(int j=0;j<n;j++){
            for(int k=0;k<j;k++){
                if(way[j][k]==2){
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
