#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n , m , a[500005] , c[300005] , b[300005];
bool isri = 1 , ish[300005] , isad = 1 , h[300005];
int main(){
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(0) , cout.tie(0);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++){
        cin >> a[i];
        if(a[i] < a[i - 1]){
            isri = 0;
        }
        if(h[a[i]] and a[i] != a[i - 1]){
            isad = 0;
        }
        else{
            h[a[i]] = 1;
        }
    }
    if(isri or isad){
        for(int i = 1 ; i <= n ; i ++){
            c[a[i]] = i;
        }
        for(int i = 1 ; i <= m ; i ++){
            cout << c[i] << ' ';
        }
        return 0;
    }
    for(int k = 1 ; k <= n ; k ++){
        int pos = 0;
        for(int i = 1 ; i <= n ; i ++){
            b[i] = 0;
        }
        for(int i = k ; i <= n ; i ++){
            if(!ish[a[i]]){
                ish[a[i]] = 1;
                b[++pos] = a[i];
            }
            else{
                while(b[pos] != a[i]){
                    ish[b[pos]] = 0;
                    pos --;
                }
            }
        }
        for(int i = 1 ; i <= m ; i ++){
            c[i] += ish[i];
            ish[i] = 0;
        }
    }
    for(int i = 1 ; i <= m ; i ++){
        cout << c[i] << ' ';
    }
    return 0;
}