#include<bits/stdc++.h>
using namespace std;
int n, k;
long long ans;
struct Node{
    long long l;
    char c;
}cnt[200005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> cnt[i].l >> cnt[i].c;
    }
    long long i = 1, j = n;
    while(i <= j){
        if(cnt[i].c != cnt[j].c){
            if(cnt[i].l == cnt[j].l){
                ans += cnt[i].l;
                cnt[j].l = 0;
                cnt[i].l = 0;
                i++;
                j--;
                continue;
            }
            if(cnt[i].l > cnt[j].l){
                ans += cnt[j].l;
                cnt[i].l -= cnt[j].l;
                cnt[j].l = 0;
                j--;
                continue;
            }
            else{
                ans += cnt[i].l;
                cnt[j].l -= cnt[i].l;
                cnt[i].l = 0;
                i++;
                continue;
            }
        }
        else{
            if(cnt[i].l == cnt[j].l){
                cnt[i].l = cnt[j].l = 0;
                i++;
                j--;
                continue;
            }
            if(cnt[i].l > cnt[j].l){
                cnt[i].l -= cnt[j].l;
                cnt[j].l = 0;
                j--;
                continue;
            }
            else{
                cnt[j].l -= cnt[i].l;
                cnt[i].l = 0;
                i++;
                continue;
            }
        }
    }
    cout << ans + cnt[n /2].l;
    return 0;
}
