#include<bits/stdc++.h>
#include<stack>
using namespace std;
int n, m;
int a[500010];
int sum[300010];
bool iff[300010];
stack <int> mi;
int main(){
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        for (int k = 1; k <= m ; k++){
            iff[k] = 0;
        }
        for(int j = i ; j <= n ; j++){
            
            if (iff[a[j]] == 1){
                while (mi.top() != a[j]){
                    mi.pop();
                }
                mi.pop();
            }
            mi.push(a[j]);
            iff[a[j]] = 1;
        }
        while(!mi.empty()){
            sum[mi.top()]++;
            mi.pop();
        }
    }
    for (int i = 1; i <= m ; i++){
        cout << sum[i] << ' ';
    }
    return 0;
}