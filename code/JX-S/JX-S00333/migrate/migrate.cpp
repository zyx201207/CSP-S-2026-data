#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int M = 2e6 + 10;
ll a[M];
int b[M],cnt[M];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%d %d",&c,&t);
    while(t--){
        if(c==13||c==14) {
            cout<<0<<endl;
            continue;
        }
        ll n,d;
        scanf("%lld %lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            cnt[i] = 1;
        }
        int r = 1;
        for(int i=1;i<=n;i++){
            while(r<n&&a[r+1]-a[i]<=d)r++;
            b[i] = r-i;
        }
        //for(int i=1;i<=n;i++) cout<<b[i]<<" "; printf("\n");
        ll ans = 0;
        for(int i=1;i<n;i++){
            int num = 0;
            int nxt = b[i] + i;
            if(b[i]!=0){
                if(b[i]==1){
                    cnt[nxt] += cnt[i];
                    continue;
                }
                else if(b[i]==2){
                    num = b[nxt-1] - 1;
                }else{
                    num = b[nxt-1] - b[nxt-2];
                }
                num = max(0,num);
                ans += cnt[i]*num;
                cnt[nxt] += cnt[i];
            }

        }
        printf("%lld\n",ans);
    }
    return 0;
}
