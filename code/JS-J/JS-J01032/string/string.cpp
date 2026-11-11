#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    char a[8350000];
    long long num;
    int cnt = 0;
    int k;
    cin >> k;
    num = 0;
    for(int i = 1; i <= k; i++){
        int p = 0;
        char q = '0';
        cin >> p >> q;
        for(int j = 1 + num; j <= p + num; j++){
            a[j] = q;
        }
        num += p;
    }
    for(int i = 1;i <= num; i++){
        cout << a[i];
    }
    for(int poi = 1;poi <= num/2; poi++){
        if (a[poi] != a[num + 1 - poi]){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
