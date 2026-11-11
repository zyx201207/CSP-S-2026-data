#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=2e5+5;
int n,m,a[N],f[N],g[M],inst[M],cnt[M];
stack<int> st;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>a[i],++cnt[a[i]];
    reverse(a+1,a+n+1);
    for (int i=1;i<=n;++i){
        while(!st.empty()&&inst[a[i]]) f[st.top()]=i,--inst[a[st.top()]],st.pop();
        st.push(i);
        ++inst[a[i]];
    }
    while(!st.empty()) f[st.top()]=n+(1-cnt[a[st.top()]]%2||st.top()==1),st.pop();
    for (int i=1;i<=n;++i)
        g[a[i]]+=f[i]-i;
    for (int i=1;i<=m;++i)
        cout<<g[i]<<" ";
    return 0;
}