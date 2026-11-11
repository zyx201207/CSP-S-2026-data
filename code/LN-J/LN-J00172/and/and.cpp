#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[200005],max01 = -114514,ans = -114514;
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        max01 = max(max01,a[i]);
    }
    if(m==1)
        printf("%d",max01);
    else if(m==n){
        ans = a[1];
        for(int i = 2;i<=n;i++){
            ans = ans&a[i];
        }
        printf("%d",ans);
    }
    else if(m==2){
        for(int i = 1;i<=n;i++){
            for(int j = i+1;j<=n;j++){
                ans = max(ans,a[i]&a[j]);
            }
        }
        printf("%d",ans);
    }else{
        printf("0");
    }
    printf("\n");
    return 0;
}
