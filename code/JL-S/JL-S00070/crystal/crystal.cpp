#include<bits/stdc++.h>
using namespace std;

int a[500005], b[500005];
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int ma = 1000000000;
    for(int i = 1; i <= n / 2; i++){
        ma = min(a[n / 2] - a[i], ma);
        b[i] = ma;
        for(int j = n / 2 + 1; j <= n + 1; j++){
            ma = min(a[i] - a[n / 2], ma);
            b[j] = ma; 
        }
    }
    int s = 0;
    int i = m;
    while(i >= 0){
        if(b[m] <= m){
            s++;
            i--;
            if(b[m] + b[m - 1] <= m){
                s++;
                i--;
                if(b[m] + b[m - 1] + b[m - 2] <= m){
                    s++;
                    i--;
                }
                else{
                    break;
                }
            }
            else{
                break;
            }
        }
        else{
            break;
        }
    }
    cout << s;
    return 0;
}
