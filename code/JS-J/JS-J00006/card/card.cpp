#include<bits/stdc++.h>
using namespace std;

int n, m, a[5001], ans[3001];
int s[5001];

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        printf("%d", a[i]);
    }
    for(int i = n; i >= 1; i--){
        printf("%d ", i);
    }
 return 0;
}
