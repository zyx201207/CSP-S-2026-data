#include<bits/stdc++.h>
using namespace std;
int n, m, a[200005], ans[5005];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        bool cnt[3005] = {0};
        stack<int> st;
        for(int j = i; j <= n; j++){
            st.push(a[j]);
            if (cnt[a[j]] == 0) cnt[a[j]] = 1;
            else{
                st.pop();
                while(!st.empty()){
                    if(st.top() == a[j]){
                        break;
                    }
                    st.pop();
                }
            }
        }
        int an[5005] = {0};
        while(!st.empty()){
            an[st.top()] = 1;
            st.pop();
        }
        for(int j = 1; j <= m; j++){
            ans[j] += an[j];
        }
    }
    for(int i = 1; i <= m; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
