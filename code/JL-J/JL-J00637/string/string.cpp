#include<bits/stdc++.h>
using namespace std;
int a[200001];
char b[200001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    int N = 0;
    for(int i = 1; i <= n; i++){
        int x;
        char y;
        cin >> x >> y;
        N += x;
        a[i] = x;
        b[i] = y;
    }
    long long sum = 0;
    int keyi = 1,keyj = n;
    int i = a[keyi],j = a[keyj];
    while(1){
        if(keyi >= keyj){break;}
        long long k = min(i,j);
        i -= k;
        j -= k;
        if(b[keyi] != b[keyj]){sum += k;}
        if(i == 0){keyi++; i = a[keyi];}
        if(j == 0){keyj--; j = a[keyj];}
    }
    cout << sum;
}
