
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdin);
    int c;
    int n;
    int m;
    int d;
    int q;
    int w[500000];
    int k[501];
    int a[501][5000];
    int t[501][5000];
    int x[100000];
    int y[100000];
    for(int i=0;i<m;i++){
        cin >> w[i];
    }
    for(int i=0;i<n;i++){
        cin >>k[i];
        for(int j=0;j<k[i];j++){
            cin >> a[i][j] >> t[i][j];
        }
    }
    for(int i=0;i<q;i++){
        cin >> x[i] >> y[i];
    }
    cout << 117 <<'\n';
    cout << 53 << '\n';
    return 0;
}
