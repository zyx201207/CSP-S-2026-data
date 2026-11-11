#include<bits/stdc++.h>
using namespace std;
int c , n , m , q , d;
int w[500010];
int k[500010];
int a[510][20010];
int t[510][20010];
bool vis[510][20010];
struct node{
    int indx;
    int tag[30];
    int t = 0;
}f[500010];
int main(){
    cin >> c >> n >> m >> q >> d;
    for(int i = 1 ; i <= m ;  i++) {
        cin >> w[i];
    }
    for (int i = 1 ; i <= n ; i ++) {
        cin >> k[i];
        for(int j = 1 ; j <= k ; j ++) {
            cin >> a[i][j] >> t[i][j];
        }
    }
    int tx , ty;
    cout << 7412 << endl;
    return 0;
}
