#include <bits/stdc++.h>
using namespace std;
long long n,x,cnt = 0;
char a;
string s = "",res1 = "",res2 = "",res3 = "";
bool check(string s1){
    long long l = 0,r = s1.size() - 1;
    while(l <= r){
        if(s1[l] == s1[r]){
            l++;
            r--;
        }else{
            return false;
        }
    }
    return true;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i = 1;i <= n;i++){
        scanf("%lld",&x);
        cin >> a;
        for(int j = 1;j <= x;j++){
            s += a;
        }
    }
    if(check(s)){
        cout << "0";
        return 0;
    }
    long long m = s.size() / 2;
    res1 = s.substr(0,m);
    for(long long i = res1.size() - 1;i >= 0;i--){
        res3 += res1[res1.size() - i - 1];
    }
    if(s.size() % 2 == 0){
        res2 = s.substr(m,s.size() - m);
        for(long long i = 0;i < res1.size();i++){
            if(res2[i] != res3[i]){
                cnt++;
            }
        }
        printf("%lld",cnt);
    }else{
        res2 = s.substr(m + 1,s.size() - m);
        for(long long i = 0;i < res3.size();i++){
            if(res2[i] != res3[i]){
                cnt++;
            }
        }
        printf("%lld",cnt);
    }
    return 0;
}
