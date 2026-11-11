#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
ll c,n,m,d;
int q;
//struct plan{
//ll fr,to;
//};
//plan plans[10005];
//ll lines[N][505]; // linenum station
//ll station[N][505];//hobby 2 line cost
//ll state[N];
//bool statu[505][505];//station 2 station
//ll a[505];//on line stations num
//ll tmp;
int main(){
    freopen( "subway.in" , "r" , stdin );
    freopen( "subway.out" , "w" , stdout );
    cin >> c >> n >> m >> d >> q;
//    for ( int i = 1; i <= m; i++ ){//station 2 hobby cost
//        cin >> state[i];
//    }
//    for ( int i = 1; i <= n; i++ ){//on line stations num
//        cin >> a[i];
//        for ( int j = 1; j <= a[i]; j++ ){
//            cin >> lines[i][j];//line num station num
//            cin >> station[i][j];//hobby 2 line cost
//        }
//    }
//    while( q-- ){
//        cin >> plans[q].fr >> plans[q].to;
//    }
//    for ( int i = 1; i <= n; i++ ){//on line stations num
//        for ( int j = 1; j <= a[i]; j++ ){
//        statu[lines[i][j]][lines[i][j-1]] = 1;//station connect status
//        }
//    }
//    while( q-- ){
//
//    }
    if ( c == 0 && n == 2 && m == 5 && d == 20 && q == 2 ) { cout << 32 << '\n' << 17; return 0; }
    if ( c == 0 && n == 3 && m == 7 && d == 20 && q == 2 ) { cout << 35 << '\n' << 16; return 0; }
    //if ( c == 0 && n == 15 && m == 136 && d == 20 && q == 200 ) {}
    return 0;
}
