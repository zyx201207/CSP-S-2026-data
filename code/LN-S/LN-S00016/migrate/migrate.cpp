#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std ;
const int N = 2e6+10;
const int INF = 0x3f3f3f3f;
long long q[N];
long long intabs(long long x){
    return (x>0?x:-x);
}
long long dis[N];
long long cnt[N];
long long x[N];
long long n,d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1 ; i <= n ; i ++){
            cin >> x[i];
        }
        int ans = 0;
        for(int i = 1 ; i <= n ; i ++){
            int l = i ;
            for(int o = i ; o <= n ; o ++)
                cnt[o] = 1;
            memset(dis,INF,sizeof dis);
            dis[l] = 0 ;
            for(int j = i ; j <= n ; j ++){
                while(x[j]-x[l]>d) l++;
                for(int k = l ; k < j ; k ++){
                    if(dis[j]>dis[k]+1){
                        dis[j] = dis[k]+1;
                        cnt[j] = cnt[k];
                    }
                    else if(dis[j]==dis[k]+1)
                        cnt[j] += cnt[k] ;
                    else break;
                }
            }
            for(int i = 1 ; i <= n ; i ++){
                ans += (cnt[i]==2);
            }
        }
        cout << ans << "\n" ;
    }
    fclose(stdin);
    fclose(stdout);
    return 0 ;
}
