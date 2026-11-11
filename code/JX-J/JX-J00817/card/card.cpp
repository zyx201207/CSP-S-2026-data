#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
int n, a[N], m, head[M], ans[M];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        head[a[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        int x = i;
        while(x <= n){
            if(head[a[x]] != x)x = head[a[x]];
            else{
                ans[a[x]]++;
                x++;
            }
        }
    }
    for(int i = 1; i <= m; i++)cout << ans[i] << " ";
}

