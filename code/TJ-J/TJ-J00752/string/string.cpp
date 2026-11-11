#include<bits/stdc++.h>
using namespace std;
long long n,cnt[200005],p[200005],d1[200005],d2[200005],g,c,ans = 0;
char a[200005];
int bol = 1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
            cin >> cnt[i] >> a[i];
            p[i] = a[i] - 'a';
    }
    if(g % 2 != 0){
        g--;
        bol = 0;
    }
    if(n==1){
        cout << "0";
        return 0;
    }
    for(int i = 1;i <= n;i++){
        g += cnt[i];
    }
    for(int i = 1;i <= g/2;i++){
        d1[i] = p[i];
    }
    int o = 0;
    for(int i = g;i >= g/2+1;i--){
        o++;
        d2[o] = p[i];
    }
    c = 1;
    while(c != g/2){
            if(d1[c] != c)ans++;
            if(d2[c] != c)ans++;
        c++;
    }
    cout << ans << endl;
}
