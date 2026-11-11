#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<char> c(n + 1);
    for(int i = 1;i <= n; i++){
        cin >> a[i] >> c[i];
    }
    int i = 1, j = n;
    long long ans = 0;
    while(1){
        if(i >= j){
            break;
        }
        if(c[i] == c[j]){
            if(a[i] < a[j]){
                a[j] -= a[i];
                i++;
            }else if(a[i] == a[j]){
                i++;
                j--;
            }else{
                a[i] -= a[j];
                j--;
            }
        }else{
            if(a[i] < a[j]){
                ans += a[i];
                a[j] -= a[i];
                i++;
            }else if(a[i] == a[j]){
                ans += a[i];
                i++;
                j--;
            }else{
                ans += a[j];
                a[i] -= a[j];
                j--;
            }
        }
    }
    cout << ans;
    return 0;
}
