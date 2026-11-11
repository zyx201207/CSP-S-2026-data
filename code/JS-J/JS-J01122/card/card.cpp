#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],vis[300005],cnt[300005];
stack<int> st;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        while(!st.empty()) st.pop();
        for(int j=i;j<=n;j++){
            if(vis[a[j]]){
                while(st.top()!=a[j]){
                    vis[st.top()]=0;
                    st.pop();
                }
                st.pop();
                vis[a[j]]=0;
            }
            st.push(a[j]);
            vis[a[j]]=1;
        }
        for(int i=1;i<=m;i++) cnt[i]+=vis[i];
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
    return 0;
}
