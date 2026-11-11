#include <bits/stdc++.h>
using namespace std;


int main(){


    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);


    int n;
    int nums;
    char letter;
    int cnt = 0;
    cin >> n;
    string pingjie;
    for(int i = 1 ; i <= n ; i++){
        cin >> nums >> letter;
        for(int j = 1 ; j <= nums;j++){
            pingjie += letter;
            cnt++;
        }
    }
    string fanzhuan;
    for(int i = cnt-1 ; i >= 0 ; i--){
        fanzhuan += pingjie[i];
    }
    int ans = 0;
    for(int i = 0 ; i <= (cnt-1)/2 ; i++){
        if(pingjie[i] != fanzhuan[i]){
            ans++;
        }
    }
    cout << ans;

    return 0;
}
