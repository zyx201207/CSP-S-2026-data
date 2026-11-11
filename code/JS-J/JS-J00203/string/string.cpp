#include<bits/stdc++.h>
using namespace std;
int n,cnt;
char c[200005];
int a[200005];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    bool flag = 0;
    for(int i = 1;i <= n;i++)
        cin >> a[i] >> c[i];
    for(int i = 1;i < n;i++){
        if(c[i] != c[i+1]){
            flag = 1;
            break;
        }
    }
    if(!flag){
        cout << 0;
        return 0;
    }
    int pos = 1;
    cnt = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= a[i];j++){
            s[pos] = c[i];
            pos++;
        }
    }
    for(int i = 1;i*2 < pos;i++){
        if(s[i] != s[pos-i] && i != (pos-i)){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
