#include <bits/stdc++.h>
using namespace std;
string a,a1,b,b1;
int c1,c2,p1,p2,z1,z2,g1,g2,ans[4];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a >> a1 >> b >> b1;
    c1 = (a[0] - '0') * 10 + (a[1] - '0');
    c2 = (b[0] - '0') * 10 + (b[1] - '0');
    p1 = (a1[0] - '0') * 10 + (a1[1] - '0');
    p2 = (b1[0] - '0') * 10 + (b1[1] - '0');
    if(a1[2] == 'F') a1[2] = 'E';
    if(b1[2] == 'F') b1[2] = 'E';
    z1 = a1[2] - 'A' + 1;
    z2 = b1[2] - 'A' + 1;
    if(z1 <= 3) g1 = 1;
    else g1 = 2;
    if(z2 <= 3) g2 = 1;
    else g2 = 2;
    if(c1 == c2){
        ans[0] = 1;
        if(p1 == p2){
            ans[1] = 1;
            if(g1 == g2){
                ans[2] = 1;
                if(abs(z1 - z2) == 1) ans[3] = 1;
            }
        }
    }
    for(int i = 0;i <= 3;++i) cout << ans[i];
    return 0;
}
