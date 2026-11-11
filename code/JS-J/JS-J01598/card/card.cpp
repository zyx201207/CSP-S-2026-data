#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
bool f[300005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i < n + 1;i++){
        cin >> a[i];
    }
    for (int i = 1;i < n + 1;i++){
        stack <int> st;
        memset(f,0,sizeof(f));
        for (int j = i;j < n + 1;j++){
            int u = a[j];
            if (f[u]){
                while (st.top() != u){
                    f[st.top()] = 0;
                    st.pop();
                }
            }
            else{
                st.push(u);
                f[u] = 1;
            }
        }
        while(!st.empty()){
            ans[st.top()]++;
            st.pop();
        }
    }
    for (int i = 1;i < m + 1;i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
