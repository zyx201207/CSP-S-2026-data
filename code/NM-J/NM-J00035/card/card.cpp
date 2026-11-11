#include <bits/stdc++.h>
using namespace std;
int n,m,a[100005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n>> m;
    for(int i =1;i <= n;i++){
        cin >> a[i];
    }for(int i = 1;i <= m;i++){
        for(int j = n;j >= 1;j--){
            if(a[j]==i){
                cout << j <<" ";
                break;
            }
        }
    }
    return 0;
}
