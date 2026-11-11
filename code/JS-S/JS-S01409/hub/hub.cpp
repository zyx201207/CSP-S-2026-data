#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;
int read(){
    int f = 1,x = 0;
    char c = getchar();
    while(!isdigit(c))
        f = c == '-' ? -1 : 1,c = getchar();
    while(isdigit(c))
        x = (x << 3) + (x << 1) + (c ^ 48),c = getchar();
    return f * x;
}
int n,k;
vector<int> G[N];
void solve(){
    n = read(),k = read();
    for(int i=1;i<n;i++){
        int u = read(),v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
}
void solve2(){
    n = read(),k = read();
    for(int i=1;i<n;i++){
        int u = read(),v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if(k == n) cout<<"0\n";
    else if(k >= n/2) cout<<"1\n";
    else{
        cout<< ((n+1)/2 - k) / 4 + 1<<'\n';
    }
}
signed main(){
    // freopen("hub5.in","r",stdin);
    // freopen("hub.out","w",stdout);
    int c = read(),t = read();
    if(c >= 13 && c <= 14){
        while(t--){
            solve2();
        }
    }
    else while(t--){
        solve();
    }
    return 0;
}