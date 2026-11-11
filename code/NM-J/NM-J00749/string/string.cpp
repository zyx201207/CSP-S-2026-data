#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int ans=0,n;
    string a[201000];
    int b[201000];
    cin >> n;
    for(int i = 0;i <= n;i++){
        cin >> b[i] >> a[i];
    }
    string s[201000];
    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= b[i];j++){
                s[i] += a[i];
        }
    }
    for(int i = 0;i <= n;i++){
        if(s[i] == s[n+1-i]){
            cout << "0";
            break;
        }
        else{
            ans++;
        }
    }
    cout << ans;
    return 0;
}
