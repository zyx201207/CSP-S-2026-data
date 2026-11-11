#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    int e=0;
    cin >> n;
    char s[8200000];
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin >> a >> c;
        for(int j=0;j<a;j++){
            s[e]=c;
            e++;
        }
    }
    int q=0;
    for(int i=1;i<=e/2;i++){
        if(s[i]!=s[n-i]){
            q++;
        }
    }
    cout << q;
    return 0;
}
