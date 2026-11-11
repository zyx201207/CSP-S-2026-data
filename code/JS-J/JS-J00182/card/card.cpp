#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    int n , m , a[500001] , num[300001];
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++)
        cin >> a[i];
    for (int i = 1 ; i <= n ; i++){
        vector<int> v;
        for (int j = i ; j <= n ; j++){
            for (int k = 0 ; k < (int)v.size() ; k++){
                if (v[k] != a[j]) while (k == (int)v.size()) v.pop_back();
            }
            v.push_back(a[j]);
        }
        for (int k = 0 ; k < (int)v.size() ; k++) num[k]++;
    }
    for (int i = 1 ; i <= m ; i++) cout << num[i] << ' ';
    return 0;
}
