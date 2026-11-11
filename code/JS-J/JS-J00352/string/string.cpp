#include <bits/stdc++.h>
using namespace std;

struct node{
    int len = 0;
    char sx = '\0';
}s[200005];

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,x;char c;
    cin >> n;
    long long ans = 0,idx = 1;
    for(int i = 1;i <= n;i++){
        cin >> x >> c;
        s[i].len = x;
        s[i].sx = c;
        idx += 1LL*x;
    }
    int i = 1,j = n;
    while(i < j){
        if(s[i].len == s[j].len){
            if(s[i].sx != s[j].sx){
                ans += s[i].len;
            }
            i++,j--;
        } else {
            if(s[i].len > s[j].len){
                if(s[i].sx != s[j].sx){
                    ans += 1LL*s[j].len;
                }
                s[i].len -= s[j].len;
                j--;
            } else {
                if(s[i].sx != s[j].sx){
                    ans += 1LL*s[i].len;
                }
                s[j].len -= s[i].len;
                i++;
            }
        }
    }
    cout << ans;
    return 0;
}
