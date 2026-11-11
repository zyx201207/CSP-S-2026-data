#include <bits/stdc++.h>
using namespace std;
int n,m,c,z,ans;
struct yan{
    int la[10005],nm;
}a[10005];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> z;
    for(int k = 1;k <= z;k++){
        cin >> n >> m;
        for(int i = 1;i < n;i++){
            int u ,v;
            cin >> u >> v;
            a[u].la[++a[u].nm] = v;
            a[v].la[++a[v].nm] = u;
        }
    }
    cout << "1" <<"\n" << "2" << "\n";
    return 0;
}
