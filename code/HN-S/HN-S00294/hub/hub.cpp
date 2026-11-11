#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
int c, t, n, k;
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while(t--){
        scanf("%d%d", &n, &k);
        int a, b;
        for(int i = 1; i < n; i++){
            scanf("%d%d", &a, &b);
        }
        int m = (n-1)/2, m2 = (n+1)/2;
        if(k >= m){
            cout <<1 << endl;
            continue;
        }
        cout << m2/3 - k/3 + (bool)(m2/3 - k/3)%3 << endl;
    }
    return 0;
}
