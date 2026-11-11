#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int N = 2e6+10;

int c,t;
int n,d;
int a[N];
int sum = 0;
inline void dfs(int l,int r,int cnt){
    if (l == r && cnt != 0){
        return;
    }
    if (cnt == 0 && l != r){
        return;
    }
    if (l == r && cnt == 0){
        sum++;
        return;
    }
    for (int i = l;i <= r;i++){
        if (a[i]-a[l] <= d){
            dfs(i,r,cnt-1);
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    for (;t--;){
        //rember to clear
        scanf("%lld%lld",&n,&d);
        for (int i = 1;i <= n;i++){
            scanf("%lld",&a[i]);
        }
       // printf("1111111111\n");
        int ans = 0;
        for (int l = 1;l <= n;l++){
            for (int r = l+1;r <= n;r++){
                int x = l,cnt = 0;//cnt is most fast's fly num
                for (;;){
                    //printf("%lld\n",x);
                    if (x >= r){
                        break;
                    }
                    int L = x,R = r+1;
                    while (L+1 < R){
                        int M = (L+R)/2;
                        if (a[M]-a[x] <= d){
                            L = M;
                        }
                        else {
                            R = M;
                        }
                    }
                    cnt++;
                    x = L;            
                    if (L == x){
                        break;
                        cnt = -1;
                    }
                }
                if (cnt == -1){
                    continue;
                }
                
                sum = 0;
                dfs(l,r,cnt);
                //printf("%lld %lld %lld 88888888888\n",l,r,sum);
                if (sum == 2){
                   // printf("%lld %lld 666666666\n",l,r);
                    ans++;
                }
            }
        }
        printf("%lld\n",ans);
    }


    return 0;
}