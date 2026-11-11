#include <bits/stdc++.h>
using namespace std;
long long n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    string s = "";
    long long cnt = 0;
    while(n--){
        int a;
        char c;
        cin >> a >> c;
        while(a--){
            s += c;
        }
    }
    long long l = s.size();
    string s2 = "";
    for (int i = 0;i < l;i++){
        s2 = s[i] + s2;
    }
    if(s==s2){
        cout << cnt;
        return 0;
    }
    string s3 = s;
    for (int i = 0;i < l/2;i++){
        if(s3[i] != s[l-1-i]){
            s3[i] = s[l-1-i];
            cnt++;
            long long l2 = s3.size();
            string s4 = "";
            for (int j = 0;j < l;j++){
                s4 = s3[j] + s4;
            }
            if(s4==s3){
                cout << cnt ;
                return 0;
            }
        }
    }
    return 0;
}
