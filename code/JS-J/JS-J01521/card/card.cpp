#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[500005],nxt[500005],numf[500005],scl[500005],res[500005],in[500005],fr[500005];
int cnt[500005];
bool sc[500005];
bool fin[500005];

struct Node{
    int a,b;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    //cout << 1;
    int t = 0;
    for(int i = 1;i <= n;i ++) {
        cin >> in[i];
        if(a[t] != in[i]) a[++ t]  = in[i];
    }

    n = t;
    for(int i = 1;i <= n;i ++) {
        cnt[a[i]] ++;
        if(numf[a[i]] != 0) {
            nxt[numf[a[i]]] = i;
            fr[i] = numf[a[i]];
        }
        numf[a[i]] = i;
    }

    stack<Node> pq;
    Node tmp;
    tmp.a = 1;
    tmp.b = nxt[1];

    for(int i = 1;i <= n;i ++) {
        while(!pq.empty() && (pq.top().b <= i)) {
            pq.pop();
        }
        //cout << fr[i] << ' ';
        if(!pq.empty())scl[i] = max(pq.top().a,fr[i]);
        else scl[i] = max(0,fr[i]);

        if(nxt[i] != 0) {
            tmp.a = i;
            tmp.b = nxt[i];
            pq.push(tmp);
        }


    }

    int r = n;
    //int flag = 0;

    while(cnt[r] == 1) {
        fin[a[r]] = 1;
        res[a[r]] = r;
        r --;
        //cout << cnt[r] << ' ' << nxt[r];

    }
    if(cnt[r] != 1 && nxt[r] == 0) {
        fin[a[r]] = 1;
        res[a[r]] = r;
        r --;
           // break;
    }
    //cout << res[1];
    for(int i = 1;i <= n;i ++) {
        //cout << res[a[i]] << ' ';
        if(!fin[a[i]]) res[a[i]] += (i - scl[i]);
    }
    for(int i = 1;i <= m;i ++) {
        cout << res[i] << ' ';
    }
    return 0;
}

/*
10 3
3 1 2 1 3 2 3 1 2 1
*/

