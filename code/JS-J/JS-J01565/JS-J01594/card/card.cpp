#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e6+10;
int n,m;
int a[N];
int h[N],mp[N];
stack<int> st;
signed main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++) {
        for(int j=i;j<=n;j++) {
            if(h[a[j]]) {
                while(!st.empty()) {
                    int u=st.top();
                    h[u]=0;
                    st.pop();
                    if(u==a[j]) break;
                }
                st.push(a[j]);
                h[a[j]]=1;
            }
            else {
                st.push(a[j]);
                h[a[j]]=1;    
            }
        }
        while(!st.empty()) {
            int u=st.top();
            h[u]=0;
            mp[u]++;
            st.pop();
        }
    }
    for(int i=1;i<=m;i++) cout<<mp[i]<<" ";
    return 0;
}
/*

*/