#include<bits/stdc++.h>
using namespace std;
int n, m, a[50005], has[30005];
bool vis[50005];
stack<int> st;
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i){
        memset(vis, false, sizeof(vis));
        for (int j = i; j <= n; ++j){
            if (!vis[a[j]]){
                st.push(a[j]);
                vis[a[j]] = true;
            }else{
                while (st.top() != a[j]){
                    vis[st.top()] = 0;
                    st.pop();
                }
            }
        }
        int big = st.size();
        for (int j = 1; j <= big; ++j){
            has[st.top()]++;
            st.pop();
        }
    }
    has[a[n]] = n;
    for (int i = 1; i <= m; ++i)
        printf("%d ", has[i]);
    printf("\n");
    return 0;
}
