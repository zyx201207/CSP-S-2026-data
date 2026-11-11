#include <bits/stdc++.h>
using namespace std;
int a[200005];
long long id1[200005], id2[200005];
char c[200005];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        scanf("%d %c", &a[i], &c[i]);
    }
    for(int i = 1; i <= n; i++){
        id1[i] = id1[i-1] + a[i];
        id2[i] = id2[i-1] + a[n-i+1];
    }
    int i = 1, j = 1;
    long long l = 0, ans = 0;
    while(i <= n && j <= n){
        int x = min(id1[i]-l, id2[j]-l);
        l += x;
        if(c[i] != c[n-j+1]) ans += x;
        if(id1[i] == id2[j]) i++, j++;
        else if(id1[i] > id2[j]) j++;
        else i++;
    }
    cout << ans/2;
    return 0;
}
