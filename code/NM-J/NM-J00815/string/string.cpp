#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
string s1, s3;
long long n, idx = 0, op = 0, cnt = 0;
cin >> n;
for (int i = 1; i <= n; i ++){
    string s2;
    cin >> op >> s2;
    for (int j = 0; j < op; j ++){
       s1 += s2;
    }
}
s3 = s1;
reverse(s1.begin(), s1.end());
if (s1.size() % 2 != 0){
    for (int i = 0; i < s1.size(); i ++){
    if (s1[i] != s3[i]){
        cnt ++;
        }
    }
} else {
    for (int i = 0; i < s1.size() / 2; i ++){
    if (s1[i] != s3[i]){
        cnt ++;
        }
    }
}
if (s1.size() % 2 != 0){
     cnt = cnt / 2;
    }
   cout << cnt;
return 0;
}
