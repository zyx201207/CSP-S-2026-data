#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
const int M = 3e5+5;
int n, m;
int a[N];
int b[N];
int cnt[M];
map<int, int> mp;//the same and and the lastest
map<int, int> mpp;//lianxu jump
map<int, int> mm;
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    bool yn = true;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
        mp[a[i]] = i;
        if(i > 1 && a[i] < a[i-1]) yn = false;
    }
    if(yn){
        for(int i = 1;i <= n;i++){
            if(a[i] != a[i+1]){
                printf("%d ", i);
            }
        }
        return 0;
    }
    if(m == 2){
        for(int i = 1;i <= n;i++){
            int x = a[i];
            if(a[n] != a[i]) cnt[3-x]++;
            cnt[x]++;
        }
        cout << cnt[1] << " " << cnt[2];
        return 0;
    }
    for(int i = 1;i <= n;i++){
        int num = a[i];
        int fi = i;
        while(a[i] == num) i++;
        i--;
        mpp[fi] = i;
        //cout << fi << ": " << mpp[fi] << endl;
    }
    for(int i = 1;i <= n;i = mpp[i]+1){
        int pl = 0;
        for(int j = i;j <= n;j = mp[a[j]]+1){
            pl++;
            if(b[mm[a[j]]] == a[j] && mm[a[j]] < pl) pl = mm[a[j]];
            /*
            for(int k = pl-1;k >= 1;k--){
                if(b[k] == a[j]){
                    pl = k;
                    break;
                }
            }
            */
            b[pl] = a[j];
            mm[a[j]] = pl;
        }
        for(int j = 1;j <= pl;++j){
            cnt[b[j]]+=mpp[i]-i+1;
        }
    }
    for(int i = 1;i <= m;++i){
        printf("%d ", cnt[i]);
    }
    return 0;
}
