#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    char x;
    int num1(0), num2(0);
    int sum1(0), sum2(0);
    char a, b;
    cin >> x;
    num1 = num1*10+int(x-'0');
    cin >> x;
    num1 = num1*10+int(x-'0');

    cin >> x;
    sum1 = sum1*10+int(x-'0');
    cin >> x;
    sum1 = sum1*10+int(x-'0');

    cin >> a;

    cin >> x;
    num2 = num2*10+int(x-'0');
    cin >> x;
    num2 = num2*10+int(x-'0');

    cin >> x;
    sum2 = sum2*10+int(x-'0');
    cin >> x;
    sum2 = sum2*10+int(x-'0');

    cin >> b;
    //printf("num1: %d, sum1: %d ", num1, sum1);
    //cout << "a: " << a << endl;
    //printf("num2: %d, sum2: %d ", num2, sum2);
    //cout << "b: " << b << endl;
    if(num1 == num2){
        cout << 1;
        if(sum1 == sum2){
            cout << 1;
            if((a <= 'C' && b <= 'C') || (a > 'C' && b > 'C')){
                cout << 1;
                if(abs(int(a-b)) == 1){
                    cout << 1;
                }else cout << "0";
            }else cout << "00";
        }else cout << "000";
    }else cout << "0000";
    return 0;
}
