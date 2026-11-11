#include<bits/stdc++.h>
using namespace std;

long long ans[300005] , a[500005] , v[500005] , l , r;

/*bool cmp1(S1 x , S1 y){
    return x.data < y.data;
}

bool cmp2(S2 x , S2 y){
    return x.li < y.li;
}

bool cmp3(S1 x , S1 y){
    return x.wz < y.wz;
}*/

int main(){
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    int n , m , cnt = 0;
    cin >> n >> m;

    for(int i = 1 ; i <= n ; i ++){
        cin >> a[i];
    }
    for(int i = 1 ; i <= n ; i ++){
        int r = 0;
        for(int j = i ; j <= n ; j ++){
            bool flag = false;
            for(int k = 1 ; k <= r ; k ++){
                if(v[k] == a[j]){
                    r = k;
                    flag = true;
                    break;
                }
            }
            if(!flag){
                r ++;
                v[r] = a[j];
            }
        }
        for(int i = 1 ; i <= r ; i ++){
            ans[v[i]] ++;
        }
    }
    for(int i = 1 ; i <= m ; i ++){
        cout << ans[i] << ' ';
    }
    return 0;
}
