#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    string str = "";
    long long ans = -1;
    long long cnt = 0;
    for(int i = 1;i <= n;i++){
        long long a;
        char c;
        cin >> a >> c;
        ans = max(ans,a);
        cnt += a;
        for(int j = 1;j <= a;j++){
            str += c;
        }
    }
    string s1 = "";
    for(int i = str.size()-1;i >= 0;i--){
        s1 += str[i];
    }
    if(s1 == str){
        cout << 0;
    }else if(n <= 2){
        cout << cnt - ans;
    }else{
        cout << cnt - ans -1;
    }
    return 0;
}
