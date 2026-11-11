#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ci = 0;
    long long sum = 0,zhong = 0,num = 0,shu = 0;
    cin >> n;
    vector <long long> a(n + 1);
    string b;
    string s,len_q;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> b[i];
        sum += a[i];
        num = a[i];
        for(int j = 1;j <= num;j++){
            s += b[i];
        }
    }
    if(sum % 2== 0){
        zhong = sum / 2 + 1;
    }
    else{
        zhong = sum / 2;
    }
    for(int i = zhong - 1;i >= 0;i--){
        len_q += s[i];
    }
    for(int i = zhong;i <= n;i++){
        ci++;
        if(len_q[len_q.size() - ci] != s[i]){
            shu++;
        }
    }
    cout << shu;
    return 0;
}
