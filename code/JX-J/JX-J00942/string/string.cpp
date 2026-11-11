#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;

struct node{
    char c;
    long long l;
    long long r;
};

string s;
int n, x, y;
node a[maxn];
long long ans, L, R;
long long cnt, len;

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        int ls;
        char zf;
        cin >> ls >> zf;

        if(zf != a[cnt].c){
            cnt++;
            a[cnt].c = zf;
            a[cnt].l = a[cnt - 1].r + 1;
            a[cnt].r = a[cnt].l + ls - 1;
        }else{
            a[cnt].r += ls;
        }
    }

    if(cnt == 1){
        cout << 0;
        return 0;
    }

    if(cnt == 2){
        if(a[1].r - a[1].l + 1 == a[2].r - a[2].l + 1){
            if(a[1].c != a[2].c)
                cout << a[1].r - a[1].l + 1;
            else cout << 0;
        }
        return 0;
    }

    x = 1, y = cnt;
    L = 1, R = a[cnt].r;
    while(L < R && x < y){
        len = min(L - a[x].l + 1, a[y].r - R + 1);

        if(a[x].c != a[y].c)
            ans += len;

        a[x].l = L;
        a[y].r = R;
        L += len;
        R -= len;

        if(L > a[x].r) x++;
        if(R < a[y].l) y--;
    }

    cout << ans;
    return 0;
}
