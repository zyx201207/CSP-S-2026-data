#include <bits/stdc++.h>
using namespace std;
int n,m,tool,ttool,tttool,a[500005],b[500005],c[500005];
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i = 0; i < n; i++) cin>>a[i];
    if(m == 1) cout<<n;
    else {
        for(int k = ttool; k < n; k++) {
                tool = 0;
                tttool = 0;
            for(int i = k; i < n; i++) {
                b[tool] = a[i];
                tool++;
                for(int j = 0; j < i; j++) {
                    if(b[j] == a[i]) tool = j + 1;
                }
                tttool = tool;
            }
            for(int i = 0; i < tttool - 1; i++) c[b[i]]++;
        }
        for(int i = 0; i < m; i++) {
            if(c[m] != 0) cout<<c[m]<<" ";
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
