#include <bits/stdc++.h>
using namespace std;
int n,num = 0;
string s = "";
int a[200000];
char c[200000];

bool asd(){
    for(int i = 0; i < s.size(); i++){
        for(int j = s.size(); j > 0; j--){
            if(s[i] != s[j]){
                return false;
            }
        }

    }
    return true;
}


int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> c[i];
        for(int j= 0; j < a[i]; j++){
            s += c[i];
        }
    }

    while (asd() == false){
        if (s[num] != s[s.size()-num]){
            s[s.size()-num] = s[num];
            num++;
        }
    }
    cout << num - 1;
}
