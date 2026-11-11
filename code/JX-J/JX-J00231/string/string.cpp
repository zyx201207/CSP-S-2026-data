#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s;
long long a[200005],m = 0;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> c[i];
        for(int j = 1;j <= a[i];j++){
            m++;
            s[m] = c[i];
        }
    }
    for(int i = 1;i <= m / 2;i++){
        if(s[i] !=  s[m + 1 - i]){
             ans++;
        }
    }
    cout << ans;
    return 0;
}


