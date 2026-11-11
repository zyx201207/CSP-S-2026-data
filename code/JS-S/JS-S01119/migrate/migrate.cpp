#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d2;
int a[2000010];

int d[5010][5010];
int cnt[5010][5010];
void solve(){
    memset(d,0x4f,sizeof(d));
    memset(cnt,0,sizeof(cnt));
    scanf("%lld%lld",&n,&d2);
    for(int i = 1;i<=n;i++){
        scanf("%lld",&c);
        a[i] = c;
    }
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            if(a[j]-a[i]>d2)break;
            d[i][j] = 1;
            cnt[i][j]++;
        }
    }
    for(int i = n;i>=1;i--){
        for(int j = i+1;j<=n;j++){
            if(a[j]-a[i]>d2)break;
            for(int k = j+1;k<=n;k++){
                if(d[i][k]>d[j][k]+1){
                    d[i][k] = d[j][k]+1;
                    cnt[i][k] = 1;
                }else if(d[i][k]==d[j][k]+1){
                    cnt[i][k]++;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
                if(cnt[i][j]==2)ans++;
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
//            cout<<setw(4)<<cnt[i][j];
        }
 //       cout<<endl;
    }
    printf("%lld\n",ans);
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
 //   cout<<endl;
    for(int i = 1;i<=t;i++)solve();
    return 0;
}
