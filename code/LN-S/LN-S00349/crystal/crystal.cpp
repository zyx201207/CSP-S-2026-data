#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
int a[500000],b[500000];
void paixu(){
    for (int i = 0;i < n;i ++){
        for (int j = 0;j < n;j ++){
            int mina;
            if (a[j] < b[i]){
                b[i] = a[j];
                mina = j;
            }
        }
        a[mina] = 100000000000;
    }
}
int jisuan(int t){
    int sum = 1,sum1 = 0;
    for (int i = 0;i < n-t-1;i++){
        sum1 += sum*(a[t+sum]-a[t+sum-1]);
        if (sum1 <= m){
            sum ++;
        }
        else return sum;
    }
    return sum;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    paixu();
    int k = 0;
    for (int i = 0;i < n;i++){
        int t = jisuan(i);
        if (t > k){
            k = t;
        }
    }
    cout << k;
    return 0;
}
