#include <bits/stdc++.h>
using namespace std;
int a[100005],sum[100005];
int dp[100005];
bool app(int x,int y){
    return x>y;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ma;
    scanf("%d%d",&n,&m);
    scanf("%d",&a[1]);
    sum[1]=a[1];
    ma=a[1];
    for(int i=2;i<=n;i++){
        scanf("%d",&a[i]);
        ma=max(ma,a[i]);
        sum[i]=sum[i-1]&a[i];
        //printf("%d\n",sum[i]);
    }

    if(m==1){
        printf("%d",ma);
        return 0;
    }
    if(n==m){
        printf("%d",sum[n]);
        return 0;
    }
    sort(a+1,a+n+1,app);
    printf("%d",a[m]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
