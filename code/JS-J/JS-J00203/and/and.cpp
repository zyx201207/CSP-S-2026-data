#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005],dp[25][25];
long long s;
int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    memset(a,0,sizeof(a));
    for(int i = 1;i <= n;i++){
        cin  >> a[i];
    }
    sort(a+1,a+1+n);
    if(m == 1){
        cout << a[n];
        return 0;
    }else if(n == m){
        for(int i = 2;i <= n;i++){
            a[i] &= a[i-1];
        }
        cout << a[n];
        return 0;
    }
    else if(m == 2){
        for(int i = 1;i < n;i++){
            for(int j = i+1;j <= n;j++){
                s = max((a[i] & a[j]),s);
            }
        }
        cout << s;
        return 0;
    }
    return 0;
}
