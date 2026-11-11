#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[30][30] = {0};
int n,m,C,mx = 0,ans;
int a[200010];
void solve1(){
    for(int i = 1;i<=n;i++){
        dp[1][i] = a[i];
    }
//    cout<<1<<endl;
    for(int i = 2;i<=m;i++){
        for(int j = 1;j<=n-i+1;j++){
            dp[i][j] = a[i];
            for(int k = j+1;k<=n-i+2;k++){
                dp[i][j] = max(dp[i][j],a[i]&dp[i-1][k]);
            }
        }
    }
    for(int i = 1;i<=m;i++){
        for(int j = 1;j<=n;j++){
//            cout<<dp[i][j]<<" ";
        }
//        cout<<endl;
    }
    cout<<dp[m][1];
}
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++){
        scanf("%d",&C);
        a[i] = C;
        mx = max(a[i],mx);
    }
    if(n<=20){
        sort(a+1,a+1+n,cmp);
        solve1();
    }else if(n<=2000){
        if(m==1){
            cout<<mx;
        }else if(m==2){
            for(int i = 1;i<=n;i++){
                for(int j = i+1;j<=n;j++){
                    ans = max(ans,a[i]&a[j]);
                }
            }
        }else{
            ans = a[1];
            for(int i = 2;i<=n;i++){
                ans&=a[i];
            }
            cout<<ans;
        }
    }else{

    }
    return 0;
}
