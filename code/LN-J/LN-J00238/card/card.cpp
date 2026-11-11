#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],t[300010];
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        t[a[i]]++;
    }
    for(int i=1;i<=m;i++) {
        cout<<t[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
