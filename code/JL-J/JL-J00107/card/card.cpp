#include<bits/stdc++.h>
using namespace std;

int a[5000005], b[5000005];
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int 1 <= x <= m;
        cin >> x;
        a[i] = x;
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; i++){
            if(a[i] == a[j]){
                for(int q = j; q < n; q++){
                    for(int p = 0; p < n - j; p++){
                        b[p] = a[q];
                    }
                }
                for(int q = 0; q < n - j; q++){
                    for(int p = 0; p < n; p++){
                        if(b[q] == a[p]){
                            sum++;
                        }
                    }
                    cout << " " << sum;
                }
            }
        }
    }
    return 0;
}
