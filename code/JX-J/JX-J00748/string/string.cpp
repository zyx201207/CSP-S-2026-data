#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
char c[N];
string s;
string f;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    scanf("%d",&n);

    for(int i = 1; i <= n; i++){
        scanf("%d %c",&a[i],&c[i]);
        for(int j = 1; j <= a[i]; j++){
            s += c[i];
        }
    }

    long long len = s.size();
    for(int i = len - 1; i >= 0; i--){
        f += s[i];
    }
    long long ans = 0;
    for(int i = 0; i < len; i++){
        if(s[i] != f[i]){
            ans++;
            f[len - i - 1] = f[i];
        }
    }
    cout << ans;
    return 0;
}
