#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s = "";
    int num,a,ans=0;
    char c;
    cin >> num;
    for(int i = 1;i <= num;i++){
        cin >> a >> c;
        for(int j = 1;j <= a;j++){
            s += c;
        }
    }
    for(int i = 0;i < s.length()/2;i++){
        if(s[i] != s[s.length()-i-1]) ans++;
    }
    cout << ans;
    return 0;
}

