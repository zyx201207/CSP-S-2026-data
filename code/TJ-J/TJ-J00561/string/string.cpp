#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cnt = 0;
    cin >> n;
    int a[200005];
    char b[200005];
    string s = "",str = "";
    for(int i = 0;i < n;i++){
        cin >> a[i] >> b[i];
        for(int j = 1;j <= a[i];j++){
            s += b[i];
        }
    }
    for(int i = s.size() - 1;i >= 0;i--){
        str += s[i];
    }
    int x = 0;
    for(int i = 0;i <= s.size()-1;i++){
        if(str[i] == s[i]){
            x++;
        }
    }
    if(x == s.size()){
        cout << 0;
        return 0;
    }
    int y = s.size()/2.0;
    for(int w = 1;w <= y;w++){
        if(s[y-w] != s[y+w]){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
