#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2E5 + 5;

struct Node {

    long long l, r, data;

}a[MAXN];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int n;
    cin >> n;

    long long len(0);
    for(int i = 1; i <= n; i++ ){

        a[i].l = a[i - 1].r + 1;
        cin >> a[i].r;
        len += a[i].r;
        a[i].r += a[i - 1].r;

        char ch;
        cin >> ch;

        a[i].data = int(ch - 'a');

    }

    //for(int i = 1; i <= n; i++ ) cout << a[i].l << ' ' << a[i].r << ' ' << a[i].data << '\n';

    long long curl(0);
    long long curr(len + 1);
    long long ans(0);
    for(int i = 1, j = n; i < j;){

        //cout << curl << ' ' << curr << '\n';

        if(a[i].r < len - a[j].l + 1){
            //cout << "bingoL\n";
            if(a[i].data != a[j].data) ans += (a[i].r - curl);
            curl = a[i].r;
            curr = len - a[i].r + 1;
            i++;
        }else{
            //cout << "bingoR\n";
            if(a[i].data != a[j].data) ans += (curr - a[j].l);
            curl = len - a[j].l + 1;
            curr = a[j].l;
            j--;
        }

    }

    cout << ans;

    return 0;
}

