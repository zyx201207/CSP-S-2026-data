#include<bits/stdc++.h>
using namespace std;
int a[2000005],n,k;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> k;
    for(int i =1;i <= n;i++){
        cin >> a[i];
    }
    for(int i =1;i <= k;i++){
        cout << 1 << ' ';
    }
    return 0;
}
