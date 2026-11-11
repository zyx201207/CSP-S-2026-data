#include<bits/stdc++.h>
using namespace std;

long long n = 0, a[200010], ans = 0, sum = 0;
char b[200010];

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> b[i];
        sum += a[i];
    }
    long long sum2 = 0, sum3 = 0, i = 0, j = n + 1;//no open long long see elders(?)
    char c = '0', d = '0';
    while(true){
        if(i == n && j == 1){
            break;
        }
        if(sum2 == sum3){
            i++;j--;
            sum2 += a[i];
            sum3 += a[j];
            if(b[i] != b[j]){
                ans += min(a[i], a[j]);
            }
        }
        else if(sum2 < sum3){
            i++;
            sum2 += a[i];
            if(b[i] != b[j]){
                ans += min(a[i], sum3 - sum2 + a[i]);
            }
        }
        else{
            j--;
            sum3 += a[j];
            if(b[i] != b[j]){
                ans += min(a[j], sum2 - sum3 + a[j]);
            }
        }
        //cout << i << " " << j << " " << sum2 << " " << sum3 << " " << ans << endl;
    }
    cout << ans / 2;
    return 0;
}
