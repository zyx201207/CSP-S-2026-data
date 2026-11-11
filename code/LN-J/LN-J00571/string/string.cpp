#include <bits/stdc++.h>
using namespace std;
int n,p = 0;
int a[200001];
char c[200001];
char s[100000001];
char g[100000001];
int ap = 0;
bool hui(char s[]){
    int t = 1;
    for (int i = p;i > 0;i--){
        g[t] = s[i];
        t++;
    }

    bool o = 1;
    for (int i = 1;i <= p;i++)
        if (g[i] != s[i]){
            o = 0;
            ap++;
        }
    if (o)
        return 1;

    return 0;
}
int main(){
    freopen("string.in",'r',stdin);
    freopen("string.out",'w',stdout);

    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> a[i] >> c[i];
        while(a[i]){
            p++;
            s[p] = c[i];
            a[i]--;
        }
    }

    if (hui(s)){
        cout << 0;
        return 0;
    }

    cout << ap / 2;

    return 0;
}
