#include <bits/stdc++.h>
using namespace std;
int a[50010],h[30010],p[30010];
stack<int> st;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    for(int i = 1;i<=n;i++){
        for(int j = i;j<=n;j++){
            if(h[a[j]]){
                while(!st.empty()&&st.top()!=a[j]){
                    h[st.top()]=0;
                    st.pop();
                }
                st.pop();
            }
            st.push(a[j]);
            h[a[j]]=1;
        }
        while(!st.empty()){
            p[st.top()]++;
            st.pop();
        }
    }
    for(int i = 1;i<=m;i++){
        cout << p[i] << ' ';
    }
    return 0;
}

