#include<bits/stdc++.h>
using namespace std;
int n , m , in , wei;
int tianyi[200010][32];
bool weii[200010];
int aa[32];
long long ans;
void chai(int k , int n1){
    int i = 1;
    while(k != 0){
        
        tianyi[n1][i] = k % 2;
        if(k % 2 == 1){
            aa[i] += 1;
        }
        k /= 2;
        i++;
    }
    
}

int main(){
    freopen("and.in" , "r" , stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        cin >> in;
        chai(in, i);
    }
    for(int i = 31 ; i >= 1 ; i--){
        if(aa[i] >= m){
            wei = i;
            ans += int(pow(float(2), float(wei - 1)));
            break;
        }
    }
    for(int i = 1; i <= n ; i++){
        if(tianyi[i][wei] == 1){
            weii[i] = 1;
        }
        
    }
    while(wei >= 2){
        wei--;
        int su = 0;
        for(int i = 1; i <= n ; i++){
            if(tianyi[i][wei] == 1 && weii[i] == 1){
                su++;
            }
        }
        if(su >= m){
            ans += int(pow(float(2), float(wei - 1)));
            for(int i = 1 ; i <= n ; i++){
                if(tianyi[i][wei] == 0){
                    weii[i] = 0;
                }
            }
        }
    }
    cout << ans;
    return 0;
}