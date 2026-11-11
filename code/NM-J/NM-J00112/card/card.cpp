#include <bits/stdc++.h>
using namespace std;
int n,m;
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    vector<int> c(n),t(m+1);
    for(int i=0;i<n;i++) {
        cin >> c[i];
        t[c[i]]=i+1;
    }
    for(int i=1;i<=m;i++) {
        cout << t[i] << ' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
