#include <bits/stdc++.h>
using namespace std;
long long n,m,ans[500050];
long long a[500050];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];

    sort(a+1,a+n+1);
    for(int i = 1 ; i <= n ; i++){
        long long need = 0;
        for(int j = 1 ; j <= i ; j++){
            need = need + (a[i] - a[j]);
            //cout << need << ' ';
            if(need <= m) ans[i]++;
            else{
                cout << *max_element(ans+1,ans+n+1);
                return 0;
            }
        }
    }
    cout << *max_element(ans+1,ans+n+1);
    return 0;
}
