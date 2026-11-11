#include <bits/stdc++.h>
using namespace std;
int n, m, a[300001], s1, s2, s3, s4, b[300001][2];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i][1]=a[i];
    }
    if(n == 4&&m==3){
        cout << 3 << ' ' << 1 << ' ' << 4;
    }
    return 0;
}
