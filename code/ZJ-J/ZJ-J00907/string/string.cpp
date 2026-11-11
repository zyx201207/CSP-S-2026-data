#include<bits/stdc++.h>
using namespace std;
char misaki[200010];
long long tianyi[200010];
long long n , lnum , rnum , ans , jian;

int main(){
    freopen("string.in" , "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> tianyi[i];
        cin >> misaki[i];
    }
    int l = 1;
    int r = n;
    lnum = tianyi[l];
    rnum = tianyi[r];
    while (l < r){
        if(rnum == 0){
            r--;
            rnum = tianyi[r];
        }
        if(lnum == 0){
            l++;
            lnum = tianyi[l];
        }
        jian = min(lnum, rnum);
        if(misaki[l] == misaki[r]){

            lnum -= jian;
            rnum -= jian;
            
        }
        else{
            ans += jian;
            lnum -= jian;
            rnum -= jian;
        }
    }
    cout << ans;
    return 0;
}