#include<bits/stdc++.h>
using namespace std;

int n,a[200000000],m,max1;


int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    for(int i = 0;i < n;i++){
        for(int j = 1; j <= n;j++){
            max1 = max(a[i] && a[j],a[i] && a[j + 1]);
        }
    }
    cout << max1;

    cout << endl;
    return 0;
}
