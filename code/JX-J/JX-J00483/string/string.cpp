#include<bits/stdc++.h>
using namespace std;

long long n , L = 0 , cnt = 0;
char c[200005];
int a[200005];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> c[i];
        L += a[i];
    }
    int l = 1 , r = n;
    while(L > 0){
        int m = min(a[l] , a[r]);
        L -= 2*m;
        if(c[l] != c[r]){
            cnt += m;
        }
        a[l] -= m;
        a[r] -= m;
        if(a[l] == 0) l++;
        if(a[r] == 0) r--;
    }
    cout << cnt;


    return 0;
}
