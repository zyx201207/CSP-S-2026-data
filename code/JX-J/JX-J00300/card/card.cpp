#include <bits/stdc++.h>
using namespace std;
int a[200005], s[200005];
int t[10005][10005];
int ans[10005];
stack<int> st, st2;
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int sum = 0;
    for(int k = 1; k <= n; k++){
        st = st2;
        for(int i = k; i <= n; i++){
            st.push(a[i]);
            t[k][a[i]]++;
            if(t[k][a[i]] >= 2){
                do{
                    t[k][st.top()] --;
                    st.pop();
                }while(st.top() != a[i]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(t[i][j]) ans[j] ++;
        }
    }
    for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
    return 0;
}
