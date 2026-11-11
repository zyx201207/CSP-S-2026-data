#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int a[n + 1], appear[m + 1];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int t = 1; t <= n; t++){
        stack <int> r;
        while(!r.empty()){
            r.pop();
        }
        /*for(int i = t; i <= n; i++){
            if(r.found(a[i])){
                while(r.top() != a[i]){
                    r.pop();
                }
            }else{
                r.push(a[i]);
            }
        }
        for(int i = 1; i <= m; i++){
            if(r.found(i)){
                appear[i]++;
            }
        }*/
    }
    return 0;
}
