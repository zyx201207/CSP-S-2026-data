#include<bits/stdc++.h>
using namespace std;
#define let long long
#define var unsigned long long
const let fic = 1;
const int al = 2e6 + 10;
let a[al];
int pos[al];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in" , "r" , stdin);
    freopen("migrate.out" , "w" , stdout);
    int c , _;
    cin >> c >> _;
    while(_--){
        int n;
        let d;
        cin >> n >> d;
        for(int i = 1;i <= n;i ++)
            cin >> a[i];
        for(int i = 1;i <= n;i ++){
            pos[i] = lower_bound(a + 1 , a + n + 1 , a[i] - d) - a;
           // cout << pos[i] << ' ';
        }
       // cout << '\n';
        int ans = 0;
        for(int i = 1;i <= n - 3;i ++)
        {
                int j = upper_bound(a + 1 , a + n + 1 , a[i] + d) - a , o = i;
                j --;
                //cout  << '\n'<< 'a' << a[i] + d << 'j' << j << '\n';
                int p = 0;
                while(p < 2){
                int k = upper_bound(a + 1 , a + n + 1 , a[j] + d) - a;
                k --;
                //cout << _  << i << ' ' << ' ' << k << ' ' << j << ' ' ;
                if(k == j)break;
                if(pos[k] == j && p == 1)ans ++;
                else if(pos[k] == j - 1 && (pos[j - 1] >= o || (pos[j - 1] < i && o + 1 == j - 1))){
                    p = 1;
                    ans ++;
                }
                else break;
                o = j;
                j = k;
            }

        }
        cout << ans << '\n';
    }
    return 0;
}

/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
