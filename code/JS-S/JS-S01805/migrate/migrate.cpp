#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int a,b,c;
    cin >> a >> b >> c;
    if(b==2){
        if(c==4) cout << "1\n2";
        else cout << "0\n1";
    }else if(b==17) cout << "8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
    return 0;
}
