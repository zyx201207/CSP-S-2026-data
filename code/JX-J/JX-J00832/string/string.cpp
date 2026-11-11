#include <bits/stdc++.h>
using namespace std;
int n;
long long a[20005];
char b[20005];
long long a2[20005];
char b2[20005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        cin >> b[i];
    }
    for(int i = n; i >= 1;i--){
        a2[n - i + 1] = a[i];
        b2[n - i + 1] = b[i];
    }
    long long ans = 0;
    int i = 1,j = 1;
    while(i <= n && j <= n){
        if(b[i] != b2[j]){
            if(a[i] < a2[j]){
                a2[j] -= a[i];
                ans += a[i];
                a[i] = 0;
                i++;
            }
            else{
                a[i] -= a2[j];
                ans += a2[j];
                a2[j] = 0;
                j++;
            }
        }
        else{
            if(a[i] > a2[j]){
                a[i] -= a2[j];
                a2[j] = 0;
                j++;
            }
            else{
                a2[j] -= a[i];
                a[i] = 0;
                i++;
            }
        }
    }
    ans /= 2;
    cout << ans;
}

