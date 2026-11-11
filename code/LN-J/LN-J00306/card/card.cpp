#include<bits/stdc++.h>
using namespace std;
void e(int val, vector<int>& b){
    int l = b.size();
    for(int i = l;i >= 1;i--){
        if(b[i] == b[val]){
            for(int j = val + 1;j <= i; j++){
                b[j] = -1;
                return;
            }
        }
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1;i <= n; i++){
        cin >> a[i];
    }
    vector<int> b = a;
    vector<int> ans(m + 1, 0);
    for(int i = 1;i <= n; i++){
        for(int j = i;j <= n; j++){
            if(b[j] != -1){
                e(j,b);
            }
        }
        for(int j = 1;j <= n; j++){
            if(b[j] != -1){
                ans[b[j]]++;
            }
        }
        b = a;
    }
    for(int i = 1;i <= m; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
