#include <bits/stdc++.h>
using namespace std;
int c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        int n,d;
        scanf("%d%d",&n,&d);
        int a[2000001];
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        if(n<4){
            printf("0\n");
            continue;
        }
        int ans=0;
        for(int i=1;i<=n-3;i++){
            if(a[i]+d<a[i+3]&&a[i]+d>=a[i+2]&&a[i+2]+d>=a[i+3]&&a[i+2]+d>=a[i+3]){
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
