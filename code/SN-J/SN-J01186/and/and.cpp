#include<bits/extc++.h>
using namespace std;
int n,m,a[200005],dp[200005][2],ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<m;i++){
        dp[i][1]=a[i];
    }
    for(int i=m;i<=n;i++){
        for(int j=1;j<i;j++){
            dp[i][0]=max(dp[j][0],dp[j][1]);
            dp[i][1]=max({dp[i][1],dp[j][0]&a[i],dp[j][1]&a[i]});
        }
        ans=max({dp[i][0],dp[i][1],ans});
    }
    printf("%d",ans);
    return 0;
}
