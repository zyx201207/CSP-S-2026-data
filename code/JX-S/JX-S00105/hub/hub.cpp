#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int dfn[N],low[N],bel[N],cnt,tim,in[N];
stack<int> st;
vector<int> p[N];
void tarjan(int x){
    dfn[x]=low[x]=++tim;
    in[x]=1;
    st.push(x);
    for(auto y:p[x]){
        if(!dfn[y]){
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }else if(in[y]){
            low[x]=min(low[x],dfn[y]);
        }
    }
    if(dfn[x]==low[x]){
        cnt++;
        while(st.size()){
            auto z=st.top();
            st.pop();
            bel[z]=cnt;
            if(z==x)break;
        }
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        p[a].push_back(b);
        p[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])tarjan(i);
    }
    last=bel[1];
    cout<<1;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)solve();
    return 0;
}
