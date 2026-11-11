#include<bits/stdc++.h>
#define int long long
#define f(i , l , r) for(int i = (l);i <= (r);i ++)
#define d(i , l , r) for(int i = (r);i >= (l);i --)
#define pii pair<int,int>
#define fi first
#define sc second
#define pb push_back
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
#define lowbit(x) ((x)&-(x))
using namespace std;
const int N = 2e6 + 10;
int n , a[N] , d , nxt[N] , lst[N];
int f[N] , g[N] , f2[N] , g2[N] , mplst[N] , mpnxt[N];
vector<int>vec[N];
void work(){
    cin >> n >> d;
    f(i , 1 , n)cin >> a[i];
    sort(a + 1 , a + 1 + n);
    f(i , 1 , n){
        nxt[i] = upper_bound(a + 1 , a + 1 + n , a[i] + d) - a - 1;
        lst[i] = lower_bound(a + 1 , a + 1 + n , a[i] - d) - a;
    }
    f(i , 1 , n)f[i] = g[i] = mplst[i] = mpnxt[i] = f2[i] = g2[i] = 0;
    // int res = 0;
    // f(i , 1 , n){
    //     f(j , i + 1 , n){
    //         //cerr << i << " " << j << '\n';
    //         int u = i , all = 0;
    //         vector<int>vec1 , vec2;
    //         while(u < j){
    //             all += u;vec1.pb(u);
    //             u = nxt[u];
                
    //             if(u == nxt[u])break;
    //         }
    //         vec1.pb(j);
    //         all += j;
    //         u = j;
    //         while(u > i){
    //             all -= u;vec2.pb(u);
    //             u = lst[u];
                
    //             if(u == lst[u])break;
    //         }
    //         vec2.pb(i);
    //         reverse(vec2.begin() , vec2.end());
    //         all -= i;
    //         if(all == 1)res ++;
    //         //if(all == 1){for(int x : vec1)cout << x << " ";cout << "\n";}
    //         if(all == 1){for(int x : vec2)cout << x << " ";cout << "\n";}
    //         if(all == 1)cout << "----\n";
    //     }
    //     //cerr << i << "\n";
    // }
    // cerr << "! " << res << "\n";
    f(i , 1 , n)if(lst[i] != i)mplst[lst[i]]++;
    f(i , 1 , n)if(nxt[i] != i)mpnxt[nxt[i]] ++;
    f(i , 1 , n){
        if(nxt[lst[i]] == i){
            f[i] = f[lst[i]] + mpnxt[i] + 1 - 1;
        }
        else f[i] = mpnxt[i] + 1;
    }
    d(i , 1 , n){
        if(lst[nxt[i]] == i){
            g[i] = g[nxt[i]] + mplst[i] + 1 - 1;
        }
        else g[i] = mplst[i] + 1;
    }
    // f(i , 1 , n){
    //     if(nxt[lst[i]] == i){
    //         f[i] = f[lst[i]] + 1;
    //     }
    //     else f[i] = 1;
    // }
    // d(i , 1 , n){
    //     if(lst[nxt[i]] == i){
    //         g[i] = g[nxt[i]] + 1;
    //     }
    //     else g[i] = 1;
    // }
    // res = 0;
    // f(i , 1 , n){
    //     f(j , i + 1 , n){
    //         if(nxt[i] == lst[j]+1){
    //             res += (lst[lst[j]] == i ? f[i] : 1) * (nxt[nxt[i]] == j ? g[j] : 1);
    //         }
    //     }
    //     //cerr << i << "\n";
    // }
    // cerr << "! " << res << "\n";
    d(i , 1 , n){
		if(nxt[i] == i)continue ;
        if(lst[nxt[i]] == i-1)g2[i] += g[nxt[i]]-1;
        g2[i] += mplst[i-1];
        //f(j , i + 1 , n){
        //    if(nxt[i] > j && lst[j] == i - 1)g2[i] ++;
        //    else if(nxt[i] == j && lst[j] == i - 1)g2[i] += g[j];
        //}
    }
    int ans = 0;
    //f(i , 1 , n)cout << nxt[i] << " ";cout << "\n";
    //f(i , 1 , n)cout << lst[i] << " ";cout << "\n";
    //f(i , 1 , n)cout << f[i] << " ";cout << "\n";
    //f(i , 1 , n)cout << g2[i] << " ";cout << "\n";
    f(i , 1 , n){
		if(nxt[i] == i || nxt[i] == i + 1)continue ;
        if(lst[nxt[i]-1] == i){
			ans += f[i] * g2[nxt[i]];
			//cout << f[i] * g2[nxt[i]] << " ";
		}
        else {
			ans += g2[nxt[i]];
			//cout << g2[nxt[i]] << " ";
		}
    }
    cout << ans << '\n';
}
signed main(){
	fre("migrate");
    ios_base::sync_with_stdio(0);
    cin.tie(0) , cout.tie(0);
    int T = 1 , c;
    cin >> c >> T;
    while(T --)work();
}
/*
0 1
6 4
-3 0 1 2 3 4

0 1
6 3
0 1 2 3 4 7

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

0 1
12 2
1 3 5 7 9 10 11 12 14 16 18 20
*/
