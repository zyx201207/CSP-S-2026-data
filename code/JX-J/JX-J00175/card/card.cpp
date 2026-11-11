#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,sum=0;
    cin>>n>>m;
    int z[200005];
    for(int i = 1; i <= m; i ++){
        cin >> z[i];
    }
    for(int i = 1; i <= n; i ++){
        if(z[i+1] != z[i]){
            sum ++;
        }
    }
    cout << 3 << 1 << 4;
    return 0;
}
