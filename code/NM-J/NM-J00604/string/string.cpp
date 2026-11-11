#include<bits/stdc++.h>
using namespace std;
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n, a, b = 0;
    char c, d[20005],e[20005],f[20005];
    string S = "";
    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> a >> c;
        for (int j = 1;j <= a;j++){
            S += c;
        }

    }
    for(int i = 0;i < S.length()/2;i++){
        d[i] = S[i];
    }
    if(S.length() % 2 == 0){
        for (int i = S.length()/2;i < S.length();i++)
            e[i] = S[i];
    }else{

        for (int i = S.length()/2+1;i < S.length();i++)
            e[i] = S[i];

    }

    for (int i = S.length()/2-1;i >= 0;i--){
        f[i] = d[i];
    }
    for (int i = 0;i < S.length()/2;i++){
        if (f[i] != e[i]) b++;
    }
    cout << b;

    return 0;
}
