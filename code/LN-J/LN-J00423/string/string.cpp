#include <bits/stdc++.h>
using namespace std;

int n,a[2100000];
char c[2100000];
long long same = 0, lengtha = 0;
int main () {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
        lengtha += a[i];
    }
    int head = 1, tail = n;
    while (head < tail) {
        if (c[head] != c[tail]){
            if (a[head] > a[tail]){
                a[head] -= a[tail];
                tail--;
            }else
                if (a[head] < a[tail]){
                a[tail] -= a[head];
                head ++;
                }else{
                    head++;
                    tail--;
                }
        }else{
            if (a[head] > a[tail]){
                a[head] -= a[tail];
                same += a[tail];
                tail--;
            }else
                if (a[head] < a[tail]){
                    a[tail] -= a[head];
                    same += a[head];
                    head ++;
                }else{
                    same += a[head];
                    tail--;
                    head++;
                }
        }

    }
    lengtha /= 2;
    cout << lengtha - same;
    return 0;
}
