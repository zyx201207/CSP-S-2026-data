#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
struct Node{
    int a;
    char c;
}e[N];
int n,sum;
bool f,g;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> e[i].a >> e[i].c;
        if(e[i].a != 1){
            f = true;
        }
        if(e[i].c != e[i - 1].c && i >= 2){
            g = true;
        }
    }
    if(!g){
        cout << 0 << endl;
        return 0;
    }
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    if(n == 2){
        if(e[1].c == e[2].c){
            cout << 0 << endl;
        }
        else{
            cout << min(e[1].a,e[2].a) << endl;
        }
        return 0;
    }
    if(!f){
        int ans = n;
        for(int i = 1,j = n;i < j;i++,j--){
            if(e[i].c == e[j].c){
                ans -= 2;
            }
        }
        cout << ans / 2 << endl;
    }
    return 0;
}
