#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m,a[500005],ans[300005];


int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(ll i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(ll i = 1;i <= n;i++){
        ll sta[500005],top = 0,p[300005];
        for(ll k = 1;k <= 300005;k++){
            p[k] = 0;
        }
        for(int j = i;j <= n;j++){
            if(p[a[j]] == 0){
                sta[++top] = a[j];
                p[a[j]] = top;
            }else{
                while(top > p[a[j]]){
                    if(p[sta[top]] == top){
                        p[sta[top]] = 0;
                    }
                    top--;
                }
            }
        }
        for(ll j = 1;j <= top;j++){
            ans[sta[j]]++;
        }
    }
    for(ll i = 1;i <= m;i++){
        cout << ans[i] << " ";
    }
    return 0;
}
