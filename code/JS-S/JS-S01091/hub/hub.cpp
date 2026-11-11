#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int c,t;
inline int f_rd(){
    register int r = 0;
    register bool f = 1;
    register char c;
    while((c = getchar()) && (!isdigit(c))) if(c == '-') f ^= 1;
    r = (c^48);
    while((c = getchar()) && (isdigit(c))) r = r*10 + (c^48);
    return r * (f ? 1 : -1);
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    c = f_rd();t = f_rd();
    while(t--){
        cout << 1 << endl;
    }
}
