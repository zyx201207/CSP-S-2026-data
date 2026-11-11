#include<bits/stdc++.h>
using namespace std;
string a[200001];
int total[200001][20];
int map_[20];
int key[20] = {0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144};
bool choose[200001];
string to_2_n(int n){
    if(n == 0){return "0";}
    if(n == 1){return "1";}
    return to_2_n(n % 2) + to_2_n(n / 2);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int k;
        cin >> k;
        a[i] = to_2_n(k);
        for(int j = 0; j < a[i].length(); j++){
            total[i][j + 1] = a[i][j] - '0';
        }
    }
    for(int i = 20; i >= 1; i--){
        int sum = 0;
        for(int j = 1; j <= n; j++){
            if(total[j][i] == 1 && !choose[j]){
                sum++;
            }
        }
        if(sum >= m){
            map_[i] = 1;
            for(int j = 1; j <= n; j++){
                if(total[j][i] == 0){
                    choose[j] = true;
                }
            }
        }
    }
    int sum = 0;
    for(int i = 1; i <= 20 ;i++){
        sum += map_[i] * key[i];
    }
    cout << sum;
}
