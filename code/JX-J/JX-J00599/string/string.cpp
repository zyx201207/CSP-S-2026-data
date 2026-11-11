#include <bits/stdc++.h>
using namespace std;



int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    string s="";
    for (int i = 1; i <= n; i++){
        int a;
        char c;
        cin >> a >> c;
        for (int j = 1; j <= a; j++){
            s+=c;
        }
    }
    if(n==1){
        cout << 0;
    } else {
        int len = s.size();
        string s1,s2;
        if(len%2==0){
            int idx = len/2;
            s1=s.substr(1,idx);
            s2 = s.substr(idx);
        } else {
            int idx = len/2;
            s1 = s.substr(0,idx);
            s2 = s.substr(idx+1);
        }
        int len2 = s2.size();
        int cnt=0;
        for (int i = len2-1; i >= 0; i--){
            if(s2[i]!=s1[i]){
                cnt++;
            }
        }
        cout << cnt;
    }

    return 0;
}
