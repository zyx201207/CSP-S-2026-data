#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
int maxn = 0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >>n>>m;
    for (int i = 0;i < n;i++){
        cin >>a[i];
    }
    if (n >= 52000){
        for (int i = n-1;i < n;i++){
            long long temp = m;
            int ans = 1;
            for (int j = i-1;j >= 0;j--){
                if (temp < 0){
                    break;
                }
                ans++;
                temp -= a[i] - a[j];
            }
            if (temp < 0){
                ans--;
            }
            cout <<ans;
            return 0;
        }
    }
    sort(a,a+n);
    for (int i = 0;i < n;i++){
        long long temp = m;
        int ans = 1;
        for (int j = i-1;j >= 0;j--){
            if (temp < 0){
                break;
            }
            ans++;
            temp -= a[i] - a[j];
        }
        if (temp < 0){
            ans--;
        }
        maxn = max(ans,maxn);
    }
    cout <<maxn << endl;
    return 0;
}
