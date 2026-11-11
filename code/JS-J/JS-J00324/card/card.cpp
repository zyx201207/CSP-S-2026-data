#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[300005];
int mo[300005];
int cnt[300005];
int main(){
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    int n , m;
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        b[a[i]]++;
        mo[a[i]] = i;
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = i ; j <= n ; j++){
            if(mo[a[j]] != 0){
                cnt[a[j]]++;
                j = mo[a[j]];
            }
            else{
                cnt[a[j]]++;
            }
        }
    }
    for(int i = 1 ; i <= m ; i++){
        cout << cnt[i] << ' ' ;
    }
    cout << '\n';
    return 0;
}
