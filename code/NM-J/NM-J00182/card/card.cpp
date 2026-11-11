//I AK CSP-J!!!
#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500050];
int ans[300030];
vector<int> d;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    for(int i = 1 ; i <= n ; i++){
        d.clear();
        for(int j = i ; j <= n ; j++){
            auto it = find(d.begin(),d.end(),a[j]);
            if(it == d.end()){
                d.push_back(a[j]);
            }
            else{
                d.erase(it,d.end());
                d.push_back(a[j]);
            }
        }
        for(int i = 0 ; i < d.size() ; i++) ans[d[i]]++;
    }
    for(int i = 1 ; i <= m ; i++) cout << ans[i] << ' ';
    return 0;
}
