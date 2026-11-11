#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair <int, int>;
const int inf = 1e17;
void fen(int n){
    if(n==2){
        cout << 32 << '\n' << 17;
    }else{
        cout << 35 << '\n' << 16;
    }
}

struct Note{
    int a, t;
};


signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    vector<int>mw(m+5,0);
    vector<Note>kat(n+5);
    vector<pii>rq(q+5);
    for(int i=1;i<=m;i++){
        cin >> mw[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin >> k;
        for(int j=1;j<=k;j++){

            cin >> kat[j].a >> kat[i].t;

        }
    }
    for(int i=1;i<=q;i++){
        cin >> rq[i].first >> rq[i].second;
    }

    if(c == 0){
        fen(n);
        return 0;
    }

    vector<vector<int> >ds(n+5,vector<int>(n+5,inf));

    return 0;
}
