#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
int sum[300005],hqr[300005];
int a[500005];
bool vis[300005];
bool flag;
stack<int> st;
void k(int u){
    memset(vis,0,sizeof(vis));
    for(int i=u;i<=n;++i){
        if(!vis[a[i]]){
            st.push(a[i]);
            vis[a[i]]=1;
        }
        else{
            while(st.top()!=a[i]){
                vis[st.top()]=0;
                st.pop();
            }
        }
    }
    while(!st.empty()){
        sum[st.top()]++;
        st.pop();
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(a[i-1]>a[i]) flag=1;
        hqr[a[i]]++;
        if(a[i]>a[i-1]) hqr[a[i]]=hqr[a[i-1]]+1;
    }
    if(!flag){
        for(int i=1;i<=m;++i) cout<<hqr[i]<<" ";
    }
    else{
        for(int i=1;i<=n;++i) k(i);
        for(int i=1;i<=m;++i) cout<<sum[i]<<" ";
    }
    return 0;
}
