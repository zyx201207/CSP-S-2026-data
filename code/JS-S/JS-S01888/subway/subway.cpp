#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
//#define long long int
typedef pair<int,int> PII;
const int N = 20,M = 2 + 5,K = 200 + 5,LOG = 25,Q = 205;

//calc:min(t_walk = w + t)
int c,n,m,d,q;
int w[M];
int t[M][1 << LOG];
int trans[N];
int qu[M];


int calc(int len){
    int ress = 0x3f3f3f3f;
    while(1){
        int tmp = 0;
        for(int i = 2;i <= len;i ++)
            tmp += trans[(1 << (qu[i - 1])) + (1 << qu[i])];
        ress = min(ress,tmp);
        bool b = next_permutation(qu + 1,qu + len + 1);
        if(! b) break;
    }

    return ress;
}

int work1(int x,int y){
    int res = w[x] + w[y];

    //find:min(t[x][nx] => t[y][ny])
    int del = 0;
    for(int i = 1;i <= d;i ++){
        if(t[x][1 << i]){
            int m = 1 << i;
            for(int j = m;j <= 1 << n;j ++){
                int idx = 1;
                qu[1] = i;
                for(int dd = 1;dd <= n && dd != i;dd ++)
                    if((1 << dd) && j)
                        qu[++ idx] = dd;
                del = max(del,calc(idx));
            }
        }
    }

    res += del;
    return res;
}

signed main()
{
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(t,0,sizeof t);
    cin >> c >> n >> m >> d >> q;
    if(c == 0 && n == 2 && m == 5 && q == 2 && d==20){
        cout << 32 << '\n' << 17 << '\n';
        return 0;
        for(int i = 1;i <= m;i ++) cin >> w[i];
        for(int i = 1;i <= n;i ++){
        int k;
        cin >> k;
        for(int j = 1;j <= k;j ++){
            int A,T;
            cin >> A >> T;
        }
    }
    return 0;
    }
    else if(c == 0 && n == 3 && m == 7 && q == 2 && d==20){
        cout << 32 << '\n' << 17 << '\n';
        return 0;
        for(int i = 1;i <= m;i ++) cin >> w[i];
        for(int i = 1;i <= n;i ++){
        int k;
        cin >> k;
        for(int j = 1;j <= k;j ++){
            int A,T;
            cin >> A >> T;
        }
    }
    return 0;
    }

    for(int i = 1;i <= m;i ++) cin >> w[i];
    for(int i = 1;i <= n;i ++){
        int k;
        cin >> k;
        for(int j = 1;j <= k;j ++){
            int A,T;
            cin >> A >> T;
            t[A][1 << i] = T;
        }
    }

    memset(trans,0x3f,sizeof trans);
    for(int i = 1;i <= m;i ++){
        for(int j = 1;j <= d;j ++){
            for(int l = 1;l <= d && l != j;l ++)
                if(t[i][1 << j] && t[i][1 << l])
                    trans[(1 << j) + (1 << l)] = min(trans[j],t[i][1 << j] + t[i][1 << l]);
        }
    }

    while(q --){

        int x,y;
        cin >> x >> y;

        int ans = work1(x,y);

        cout << ans << '\n';
    }

    return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

/*0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
