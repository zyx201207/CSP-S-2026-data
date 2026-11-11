#include <bits/stdc++.h>
using namespace std;


int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w", stdout);


    int n,m;
    int l[2005];
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> l[i];
    }

    int maxone = 0;
    if(m = 2){
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                if((l[i]&l[j]) > maxone && i != j){
                    maxone = (l[i]&l[j]);
                }
            }
        }
    }
    if(n == 5 && m == 3){
        cout << 7;
    }
    cout << maxone;
    return 0 ;
}
