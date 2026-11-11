#include <bits/stdc++.h>
using namespace std;
int n, y;
vector<char> str;
char x;
void f(int n, char c){
    for (int i = 0;i < n;i++)
        str.push_back(c);
    return ;
}
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin>>n;
    for (int i = 0;i < n;i++){
        cin>>y>>x;
        f(y, x);
    }
    int l = (str.end() - str.begin()), cnt = 0;
    if (l%2 == 1){
        for (int i = 0; i < l/2;i++){
            if (str[i] != str[l-i-1]) cnt++;
        }
    }
    else {
        for (int i = 0;i < l/2;i++){
            if (str[i] != str[l-i-1]) cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}