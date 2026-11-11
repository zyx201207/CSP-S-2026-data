#include <iostream>
using namespace std;
const int MAXN = 2e5 + 5;
int a[MAXN];
char c[MAXN];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    long long sum = 0;
    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> a[i] >> c[i];
    }
    int t1 = a[1], t2 = a[n];
    for (int i = 1, j = n;i <= n && j >= 1;){
        if (t1 > t2){
            t1 -= t2;
            if (c[i] != c[j]){
                sum += t2;
            }
            j--;
            t2 = a[j];
        }else if (t1 < t2){
            t2 -= t1;
            if (c[i] != c[j]){
                sum += t1;
            }
            i++;
            t1 = a[i];
        }else{
            if (c[i] != c[j]){
                sum += t1;
            }
            i++;
            t1 = a[i];
            j--;
            t2 = a[j];
        }
    }
    cout << sum / 2;
}
