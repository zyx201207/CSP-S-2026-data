#include<bits/stdc++.h>
using namespace std;

int a[200020];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n , m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    int ma = INT_MIN;
    for(int i = 1;i <= n;i++){
        int l = a[i];
        for(int o = 1;o <= m-1;o++){
            for(int j = i+o-1;j <= n;j++)l &= a[j];
        }
        ma = max(l , ma);
    }
    cout << ma;
    return 0;
}
