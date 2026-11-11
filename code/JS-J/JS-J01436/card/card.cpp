#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
long long n, m;
long long a[N], s[M];
bool vis[M];
stack<long long> st;
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(long long i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(long long i = 1; i <= n; i++){
        memset(vis, 0, sizeof(vis));
        for(long long j = i; j <= n; j++){
            if(!vis[a[j]]){
                st.push(a[j]);
                vis[a[j]] = true;
            }else{
                while(st.top() != a[j]){
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            s[st.top()]++;
            st.pop();
        }
    }
    for(long long i = 1; i <= m; i++){
        cout << s[i] << " ";
    }
    return 0;
}