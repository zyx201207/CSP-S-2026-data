#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
int a[maxn],dp[maxn];
int main(){
	freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    scanf("%d%d",&c,&T);
    while(T--){
        int n,d;
        scanf("%d%d",&n,&d);
        memset(dp,0x3f3f,sizeof(dp));
        vector<int>cnt(n+1);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        int ans=0;
        dp[0]=0;
        if(a[1]<0){
            a[0]=a[1];
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(a[i]-a[j]>d){
                    continue;
                }else{
                    if(dp[j]+1<dp[i]){
                        dp[i]=dp[j]+1;
                        cnt[i]=1;
                    }else if(dp[j]+1==dp[i]){
                        cnt[i]++;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(cnt[i]==2){
                ans++;
            }
        }
        printf("%d\n",ans);
    }
	return 0;
}

