#include <bits/stdc++.h>
using namespace std;
int a, num, number = 0;
string spin, x, q;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "m", stdout);
    cin >> a;
    for(int i= 0; i<=a; i++){
        cin >> num >> x;
        number += num;
        int q = num;
        while(q != 0){
            spin += x;
            q -= 1;
        }
    }
    if(number % 2 == 0){
        for(int i = 1; i <= number/2; i++){
        if(spin[i+number/2-1] != spin[number/2-i]){
            q += 1;
        }
        }
    }
    else {for(int i = 1; i <= number/2; i++){
        if(spin[i+number/2] != spin[number/2-i]){
            q += 1;
        }
        }
    }
    cout << q;
    return 0;
    }
