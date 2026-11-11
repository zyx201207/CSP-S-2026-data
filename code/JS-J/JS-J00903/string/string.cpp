#include <bits/stdc++.h>
using namespace std;
long long int n, cnt, sum;
int a[20005], b[20005];
string s[20005], s1[20005], s2[10000005];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    //10~49 tepan
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> s[i];
        sum += a[i];
        b[i] = a[i];s1[i] = s[i];
    }
//    sort(b + 1, b + n + 1);
//    if(b[1] == b[n]){
//        for(int i = 1; i <= n / 2; i++){
//            if(s[i] != s[n - i + 1]){
//                cnt++;
//            }
//        }
//        cout << cnt;
//        return 0;
//    }
    sort(s1 + 1, s1 + n + 1);
    if(s1[1] == s1[n]){
        cout << 0;
        return 0;
    }
    if(n == 1){
        cout << 0;
        return 0;
    }
    if(n == 2){
        string q[20005];
        for(int i = 1; i <= a[1]; i++){
            q[i] = s[1];
        }
        for(int i = a[1] + 1; i <= a[2] + a[1]; i++){
            q[i] = s[2];
        }
//        for(int i = 1; i <= a[1] + a[2]; i++){
//            cout << q[i] << " ";
//        }
//        cout << endl;
        for(int i = 1; i <= sum / 2; i++){
            if(q[i] != q[sum - i + 1]){
                //q[i] = q[sum - i + 1];
                cnt++;
            }
        }
        cout << cnt;
        return 0;
    }
    int cnt1 = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= a[i]; j++){
            s2[cnt1] = s[i];
            cnt1++;
//            cout << s2[cnt1 - 1] << " ";
        }
    }
//    cout << endl;
    for(int i = 1; i <= sum / 2; i++){
        if(s2[i] != s2[sum - i + 1]){
//            cout << s2[i] << " " << s2[sum - i + 1] << endl;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
