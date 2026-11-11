#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m;
int cnt[N], a[N];
vector<int> vec;
int b[N];
bool flag = true;
signed main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for(int i = 1; i <= n; i ++){
        scanf("%lld", &a[i]);
        if(i != 1 && a[i] < a[i - 1]) flag = false;
    }
    if(n <= 500){
        for(int i = 1; i <= n; i ++){
            vec.clear();
            for(int j = i; j <= n; j ++){
                int pos = -1;
                int len = vec.size();
                for(int k = len - 1; k >= 0; k --){
                    if(vec[k] == a[j]){
                        pos = k;
                        break;
                    }
                }
                if(pos != -1){
                    int len2 = vec.size();
                    for(int k = pos; k < len2; k ++){
                        vec.pop_back();
                    }
                }
                vec.push_back(a[j]);
            }
            for(int j : vec){
                cnt[j] ++;
            }
        }
        for(int i = 1; i <= m; i ++){
            printf("%lld ", cnt[i]);
        }
        printf("\n");
        return 0;
    }
    int now = 0;
    if(flag){
        for(int i = 1; i <= n; i ++){
            for(int j = 0; j <= n; j ++){
                b[i] = -1;
            }
            now = 0;
            for(int j = i; j <= n; j ++){
                if(b[now] != a[j]){
                    b[++ now] = a[j];
                }
            }
            for(int j = 1; j <= now; j ++){
                cnt[b[j]] ++;
            }
        }
        for(int i = 1; i <= m; i ++){
            printf("%lld ", cnt[i]);
        }
        printf("\n");
        return 0;
    }
    return 0;
}