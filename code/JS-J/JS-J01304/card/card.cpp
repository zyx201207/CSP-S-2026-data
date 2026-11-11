#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long n,m,a[N],sum[N];
stack<int> st;
void fd(int l,int r) {
    while(!st.empty()){
        st.pop();
    }
    int idx = l,vis[N];
    memset(vis,0,sizeof vis);
    while(idx <= r){
        int now = a[idx];
        if(vis[now] == 1){
            while(!st.empty() && st.top() != now) {
                sum[st.top()] --;
                vis[st.top()] = 0;
                st.pop();
            }
        }else{
            st.push(now);
            sum[now] ++;
            vis[now] = 1;
        }
        idx ++;
    }
    return ;
}
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i ++){
        fd(i,n);
    }
    for(int i = 1;i <= m;i ++){
        cout << sum[i] << " ";
    }
    return 0;
}
