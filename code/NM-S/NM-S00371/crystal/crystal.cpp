#include <bits/stdc++.h>
using namespace std;

int n,m,q[5000],ans = 0,cut = 0
int main(){
    freopen("crystal.in","r"stdin)
    freopen("crystal.out","w"stdout)
    cin >> n >> m;
    cin >> q[5000]
    for (int i = 0;i <= n - 1;i++)
        for (int j = 1;j <= m;j++)
            if (q[i] < q[i+1])
                q[i] += (i + 1);
            else
                cnt++
    cout << cut << endl;
return 0;
}
